import time
import threading
from pynput.mouse import Controller as MouseController, Button as MouseButton
from pynput.keyboard import Controller as KeyboardController, Key
import os
import ui

# Crear instancias de controladores de mouse y teclado
mouse_controller = MouseController()
keyboard_controller = KeyboardController()

# Variables globales
reproduciendo = False  # Inicialmente no se está reproduciendo
bucle_infinito = False  # Control del bucle infinito
velocidad_eventos = 0.05  # Definir la velocidad de los eventos (en segundos)

# Función para simular los eventos del archivo
def ejecutar_eventos():
    global reproduciendo, velocidad_eventos
    
    # Verificar si el archivo de eventos existe
    if not os.path.exists("all_events.txt"):
        print("Error: El archivo de eventos no existe.")
        return

    with open("all_events.txt", "r") as file:
        eventos = file.readlines()
    
    reproduciendo = True  # Inicia ejecución de los eventos
    
    # Iniciar el bucle infinito si está marcado
    while reproduciendo:
        for evento in eventos:
            if not reproduciendo:
                break  # Salir del bucle si se ha detenido la ejecución
            evento = evento.strip()  # Eliminar saltos de línea y espacios adicionales

            # Simular los eventos de mouse
            # Detectar clics
            if "Mouse clicked" in evento:
                if "Left" in evento and "pressed" in evento:
                    # Simula el click izquierdo presionado
                    mouse_controller.press(MouseButton.left)
                    print(f"Left mouse pressed.")
                elif "Left" in evento and "released" in evento:
                    # Simula el click izquierdo liberado
                    mouse_controller.release(MouseButton.left)
                    print(f"Left mouse released.")
                elif "Right" in evento and "pressed" in evento:
                    # Simula el click derecho presionado
                    mouse_controller.press(MouseButton.right)
                    print(f"Right mouse pressed.")
                elif "Right" in evento and "released" in evento:
                    # Simula el click derecho liberado
                    mouse_controller.release(MouseButton.right)
                    print(f"Right mouse released.")

            # Detectar arrastres del mouse
            elif "Mouse dragged" in evento:
                # Extraer coordenadas de movimiento
                coords = evento.split("from")[1].split("to")
                start_x, start_y = map(int, coords[0].strip()[1:-1].split(","))
                end_x, end_y = map(int, coords[1].strip()[1:-1].split(","))
                
                # Simular la acción de presionar el botón, mover y liberar el botón
                mouse_controller.position = (start_x, start_y)  # Mover el mouse a la posición inicial
                mouse_controller.press(MouseButton.left)  # Simular el presionar
                print(f"Left mouse pressed at ({start_x}, {start_y})")
                time.sleep(velocidad_eventos)  # Pausa para simular el movimiento
                mouse_controller.move(end_x - start_x, end_y - start_y)  # Mover el mouse
                print(f"Mouse dragged to ({end_x}, {end_y})")
                mouse_controller.release(MouseButton.left)  # Simular el soltar el botón
                print(f"Left mouse released at ({end_x}, {end_y})")

            # Detectar movimiento del mouse
            elif "Mouse moved" in evento:
                # Extraer coordenadas de movimiento simple
                coords = evento.split("to")[1].strip()[1:-1]
                x, y = map(int, coords.split(","))
                # Mover el ratón a las nuevas coordenadas
                mouse_controller.position = (x, y)
                print(f"Mouse moved to ({x}, {y})")
            
            # Detectar desplazamiento del mouse (scroll)
            elif "Mouse scrolled" in evento:
                # Extraer el desplazamiento (delta)
                delta = evento.split("with delta")[1].strip()[1:-1].split(",")
                dx, dy = map(int, delta)
                # Simular el desplazamiento del mouse (scroll)
                mouse_controller.scroll(dx, dy)
                print(f"Mouse scrolled with delta ({dx}, {dy})")
            
            # Simular los eventos de teclado
            elif "Key pressed" in evento:
                key = evento.split("Key pressed: ")[1]
                # Verificar si la tecla es "Esc" y no ejecutarla
                if key.lower() == "esc":
                    print("Tecla ESC detectada, no se ejecutará.")
                else:
                    try:
                        keyboard_controller.press(key)
                        time.sleep(velocidad_eventos)  # Pausa pequeña entre las acciones
                    except Exception as e:
                        print(f"Error al presionar la tecla: {e}")

            elif "Special key pressed" in evento:
                key = evento.split("Special key pressed: ")[1]
                # Verificar si la tecla es "Esc" y no ejecutarla
                if key == str(Key.esc):
                    print("Tecla ESC detectada, no se ejecutará.")
                else:
                    if key == str(Key.esc):
                        keyboard_controller.press(Key.esc)
                        time.sleep(velocidad_eventos)

            time.sleep(velocidad_eventos)  # Pausa entre cada evento

        # Si el bucle es infinito, se reinicia
        if bucle_infinito and reproduciendo:
            print("Reiniciando reproducción de eventos...")
            continue  # Reiniciar el ciclo de eventos

        # Si ya no hay más eventos y el bucle infinito no está activado, detener la reproducción
        if not bucle_infinito:
            print("No hay más eventos, deteniendo reproducción.")
            ui.detener_rep()
            break  # Salir del bucle si no hay más eventos y no es bucle infinito

# Función para detener la reproducción
def detener_reproduccion():
    global reproduciendo
    reproduciendo = False  # Detiene la ejecución de los eventos
    print("Reproducción detenida.")