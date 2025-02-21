import time
import pyautogui
import os
import ui
from pynput.keyboard import Controller as KeyboardController, Key

# Variables globales
velocidad_eventos = 0.05  # Definir la velocidad de los eventos (en segundos)
keyboard_controller = KeyboardController()
bucle_infinito = False  # Definir si los eventos deben ejecutarse en bucle infinito

# Función para interpretar y simular los eventos
def interpretar_eventos():
    with open("all_events.txt", 'r') as file:
        eventos = file.readlines()    #separar la interpretacion y ejecucion de los eventos del mouse y del teclado para ejecutarlos en hilos distintos y simultaneos*************

    for evento in eventos:
        print(f"Procesando evento: {evento.strip()}")  # Impresión para verificar el evento actual

        if "Left mouse clicked" in evento:
            # Extraer las coordenadas y hacer clic izquierdo
            coordenada = evento.split("at")[1].strip()[1:-1]
            x, y = map(int, coordenada.split(","))
            print(f"Haciendo clic izquierdo en las coordenadas: ({x}, {y})")  # Impresión de la acción
            pyautogui.click(x, y)
            
            #Relase click izq *********
            
        elif "Right mouse clicked" in evento:
            # Extraer las coordenadas y hacer clic derecho
            coordenada = evento.split("at")[1].strip()[1:-1]
            x, y = map(int, coordenada.split(","))
            print(f"Haciendo clic derecho en las coordenadas: ({x}, {y})")  # Impresión de la acción
            pyautogui.rightClick(x, y)
            
            #Relase click der ********

        elif "Left mouse dragged" in evento or "Right mouse dragged" in evento:
            # Extraer las coordenadas de arrastre y mover el mouse mientras se mantiene presionado
            coordenadas = evento.split("from")[1].split("to")
            x1, y1 = map(int, coordenadas[0].strip()[1:-1].split(","))
            x2, y2 = map(int, coordenadas[1].strip()[1:-1].split(","))
        
            # Imprimir el movimiento en consola
            print(f"Arrastrando el mouse de ({x1}, {y1}) a ({x2}, {y2})")  # Impresión de la acción
        
            # Mantener presionado el botón del mouse en la posición de inicio
            pyautogui.mouseDown(x1, y1, button='left' if "Left" in evento else 'right')
        
            # Mover el mouse hacia la posición final (to) con la duración especificada
            pyautogui.moveTo(x2, y2, duration=1)
        
            # Soltar el botón del mouse en la posición final (to)
            pyautogui.mouseUp(button='left' if "Left" in evento else 'right')

        elif "Key pressed" in evento:
            # Extraer la tecla y presionarla
            tecla = evento.split(":")[1].strip()
            print(f"Presionando tecla: {tecla}")  # Impresión de la acción
            if tecla == "esc":
                keyboard_controller.press(Key.esc)
                keyboard_controller.release(Key.esc)
            else:
                keyboard_controller.press(tecla)
                keyboard_controller.release(tecla)

        elif "Special key pressed" in evento:
            # Aquí puedes agregar casos para teclas especiales
            tecla = evento.split(":")[1].strip()
            print(f"Presionando tecla especial: {tecla}")  # Impresión de la acción
            if tecla == "Key.esc":
                keyboard_controller.press(Key.esc)
                keyboard_controller.release(Key.esc)

        # Aplicar la velocidad de los eventos
        time.sleep(velocidad_eventos)

# Función para ejecutar los eventos del archivo
def ejecutar_eventos():
    global reproduciendo
    # Verificar si el archivo de eventos existe
    if not os.path.exists("all_events.txt"):
        print("Error: El archivo de eventos no existe.")
        return

    reproduciendo = True  # Inicia ejecución de los eventos
    while reproduciendo:
        print("Ejecutando eventos...")  # Impresión cuando se inicia la ejecución de eventos
        interpretar_eventos()  # Procesa los eventos

        if not bucle_infinito:
            print("No hay más eventos, deteniendo reproducción.")
            ui.detener_rep()  # Detener la reproducción en la interfaz de usuario
            break  # Salir del bucle si no hay más eventos y no es bucle infinito

# Función para detener la reproducción
def detener_reproduccion():
    global reproduciendo
    reproduciendo = False  # Detiene la ejecución de los eventos
    print("Reproducción detenida.")
