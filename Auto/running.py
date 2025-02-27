import time
import pyautogui
import os
import ui
from pynput.keyboard import Controller as KeyboardController, Key
import threading

# Variables globales
keyboard_controller = KeyboardController()
bucle_infinito = False  # Definir si los eventos deben ejecutarse en bucle infinito

#**********el arrastre no funciona, la simulacion del teclado tampoco**********

# Función para interpretar y simular los eventos del mouse
def interpretar_eventos_mouse():
    file_path = os.path.join(os.path.dirname(__file__), "mouse_events.txt")
    with open(file_path, 'r') as file:
        eventos = file.readlines()

    start_time = time.time()
    for evento in eventos:
        evento_time = float(evento.split(":")[0].strip().replace(",", "."))
        time.sleep(max(0, evento_time - (time.time() - start_time)))

        print(f"Procesando evento de mouse: {evento.strip()}")  # Impresión para verificar el evento actual

        if "Left mouse clicked and released" in evento:
            coordenada = evento.split("at")[1].strip()[1:-1]
            x, y = map(int, coordenada.split(", "))
            print(f"Haciendo clic izquierdo en las coordenadas: ({x}, {y})")
            pyautogui.click(x, y)
            pyautogui.mouseUp(button='left')

        elif "Right mouse clicked and released" in evento:
            coordenada = evento.split("at")[1].strip()[1:-1]
            x, y = map(int, coordenada.split(","))
            print(f"Haciendo clic derecho en las coordenadas: ({x}, {y})")
            pyautogui.rightClick(x, y)
            pyautogui.mouseUp(button='right')

        elif "Left mouse dragged" in evento or "Right mouse dragged" in evento:
            coordenadas = evento.split("from")[1].split("to")
            x1, y1 = map(int, coordenadas[0].strip()[1:-1].split(", "))
            x2, y2 = map(int, coordenadas[1].strip()[1:-1].split(", "))
            print(f"Arrastrando el mouse de ({x1}, {y1}) a ({x2}, {y2})")
            pyautogui.mouseDown(x1, y1, button='left' if "Left" in evento else 'right')
            pyautogui.moveTo(x2, y2, duration=1)
            pyautogui.mouseUp(button='left' if "Left" in evento else 'right')

# Función para interpretar y simular los eventos del teclado
def interpretar_eventos_teclado():
    file_path = os.path.join(os.path.dirname(__file__), "keyboard_events.txt")
    with open(file_path, 'r') as file:
        eventos = file.readlines()

    start_time = time.time()
    for evento in eventos:
        evento_time = float(evento.split(":")[0].strip())
        time.sleep(max(0, evento_time - (time.time() - start_time)))

        print(f"Procesando evento de teclado: {evento.strip()}")

        if "Key pressed" in evento:
            tecla = evento.split(":")[1].strip()
            print(f"Presionando tecla: {tecla}")
            if tecla == "esc":
                keyboard_controller.press(Key.esc)
                keyboard_controller.release(Key.esc)
            else:
                keyboard_controller.press(tecla)
                keyboard_controller.release(tecla)

        elif "Special key pressed" in evento:
            tecla = evento.split(":")[1].strip()
            print(f"Presionando tecla especial: {tecla}")
            if tecla == "Key.esc":
                keyboard_controller.press(Key.esc)
                keyboard_controller.release(Key.esc)

# Función para ejecutar los eventos del archivo
def ejecutar_eventos():
    global reproduciendo

    reproduciendo = True
    mouse_thread = threading.Thread(target=interpretar_eventos_mouse)
    teclado_thread = threading.Thread(target=interpretar_eventos_teclado)

    mouse_thread.start()
    teclado_thread.start()

    mouse_thread.join()
    teclado_thread.join()

    if not bucle_infinito:
        print("No hay más eventos, deteniendo reproducción.")
        ui.detener_rep()

# Función para detener la reproducción
def detener_reproduccion():
    global reproduciendo
    reproduciendo = False  # Detiene la ejecución de los eventos
    print("Reproducción detenida.")
