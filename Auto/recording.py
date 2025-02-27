import threading
from pynput import mouse, keyboard
import ui
from pynput.mouse import Listener, Button
import time

# Arreglos para almacenar los eventos
mouse_events = []
keyboard_events = []
all_events = []  # Lista global para todos los eventos

# Variables para los listeners
mouse_listener = None
keyboard_listener = None

# Variables para detectar el estado del botón
left_button_pressed = False
right_button_pressed = False
last_position = None
moving = False

# Variable para el tiempo de inicio
start_time = None

# Función para obtener el tiempo transcurrido
def get_elapsed_time():
    return time.time() - start_time

# Función para manejar el movimiento del mouse
def on_click(x, y, button, pressed):
    global left_button_pressed, right_button_pressed, last_position

    event = None  # Inicializar variable de evento

    if button == Button.left:
        if pressed:
            # Guardamos el "from" cuando se presiona el botón izquierdo
            left_button_pressed = True
            last_position = (x, y)
        else:
            # Guardamos el "to" cuando se suelta el botón izquierdo
            left_button_pressed = False
            if last_position is not None:
                # Verificar si hubo movimiento para registrar un arrastre
                if last_position != (x, y):
                    event = f"{get_elapsed_time():.2f}: Left mouse dragged from {last_position} to ({x}, {y})"
                else:
                    # Si no hubo movimiento, solo registra el clic seguido de un relase en el mismo lugar
                    event = f"{get_elapsed_time():.2f}: Left mouse clicked and released at ({x}, {y})"
            last_position = None  # Resetea la posición cuando se suelta el botón
        
    elif button == Button.right:
        if pressed:
            # Guardamos el "from" cuando se presiona el botón derecho
            right_button_pressed = True
            last_position = (x, y)
        else:
            # Guardamos el "to" cuando se suelta el botón derecho
            right_button_pressed = False
            if last_position is not None:
                # Verificar si hubo movimiento para registrar un arrastre
                if last_position != (x, y):
                    event = f"{get_elapsed_time():.2f}: Right mouse dragged from {last_position} to ({x}, {y})"
                else:
                    # Si no hubo movimiento, solo registra el clic, seguido de un relase en el mismo lugar
                    event = f"{get_elapsed_time():.2f}: Right mouse clicked and released at ({x}, {y})"
            last_position = None  # Resetea la posición cuando se suelta el botón

    else:
        return  # Ignorar otros botones

    # Añadir el evento al registro solo si se generó un evento
    if event:
        mouse_events.append(event)
        all_events.append(event)
        print(event)  # Imprimir en la consola

# Función para manejar los eventos del teclado
def on_press(key):
    try:
        event = f"{get_elapsed_time():.2f}: Key pressed: {key.char}"
    except AttributeError:
        event = f"{get_elapsed_time():.2f}: Special key pressed: {key}"

    keyboard_events.append(event)
    all_events.append(event)
    print(event)  # Imprimir en la consola

def on_release(key):
    if key == keyboard.Key.esc:
        ui.detener() # Detener el listener si se presiona ESC

# Funciones para iniciar y detener los listeners
def start_listeners():
    global mouse_listener, keyboard_listener, start_time
    all_events.clear()
    start_time = time.time()  # Inicializar el tiempo de inicio
    # Crear y comenzar los listeners
    mouse_listener = mouse.Listener(on_click=on_click)
    keyboard_listener = keyboard.Listener(on_press=on_press, on_release=on_release)

    mouse_listener.start()
    keyboard_listener.start()

    print("Listeners iniciados.")

def stop_listeners():
    global mouse_listener, keyboard_listener, all_events
    if mouse_listener is not None:
        mouse_listener.stop()
    if keyboard_listener is not None:
        keyboard_listener.stop()

    # Exportar todos los eventos a un archivo en la misma carpeta que el módulo
    base_path = "/home/franciscop/Documentos/proyectos/Inic/Auto/"
    
    with open(base_path + "all_events.txt", "w") as file:
        for event in all_events:
            file.write(event + "\n")
    print("Todos los eventos se han guardado en 'all_events.txt'.")
    all_events.clear()
    
    with open(base_path + "mouse_events.txt", "w") as file:
        for event in mouse_events:
            file.write(event + "\n")
    print("Todos los eventos del mouse se han guardado en 'mouse_events.txt'.")
    mouse_events.clear()
    
    with open(base_path + "keyboard_events.txt", "w") as file:
        for event in keyboard_events:
            file.write(event + "\n")
    print("Todos los eventos del teclado se han guardado en 'keyboard_events.txt'.")
    keyboard_events.clear()