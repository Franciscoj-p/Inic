from pynput import mouse, keyboard
import ui

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

# Funciones para manejar los eventos del mouse
def on_move(x, y):
    global last_position
    if left_button_pressed and last_position is not None:
        event = f"Left mouse dragged from {last_position} to ({x}, {y})"
        mouse_events.append(event)
        all_events.append(event)
        print(event)  # Imprimir en la consola
    if right_button_pressed and last_position is not None:
        event = f"Right mouse dragged from {last_position} to ({x}, {y})"
        mouse_events.append(event)
        all_events.append(event)
        print(event)  # Imprimir en la consola
    last_position = (x, y)

def on_click(x, y, button, pressed):
    global left_button_pressed, right_button_pressed
    if button == mouse.Button.left:
        if pressed:
            left_button_pressed = True
            event = f"Left mouse clicked at ({x}, {y})"
        else:
            left_button_pressed = False
            last_position = None  # Resetea la posición cuando se suelta el botón
            event = f"Left mouse released at ({x}, {y})"
    elif button == mouse.Button.right:
        if pressed:
            right_button_pressed = True
            event = f"Right mouse clicked at ({x}, {y})"
        else:
            right_button_pressed = False
            last_position = None  # Resetea la posición cuando se suelta el botón
            event = f"Right mouse released at ({x}, {y})"
    else:
        return  # Ignorar otros botones

    mouse_events.append(event)
    all_events.append(event)
    print(event)  # Imprimir en la consola

def on_scroll(x, y, dx, dy):
    event = f"Mouse scrolled at ({x}, {y}) with delta ({dx}, {dy})"
    mouse_events.append(event)
    all_events.append(event)
    print(event)  # Imprimir en la consola

# Función para manejar los eventos del teclado
def on_press(key):
    try:
        event = f"Key pressed: {key.char}"
    except AttributeError:
        event = f"Special key pressed: {key}"

    keyboard_events.append(event)
    all_events.append(event)
    print(event)  # Imprimir en la consola

def on_release(key):
    if key == keyboard.Key.esc:
        ui.detener() # Detener el listener si se presiona ESC

# Funciones para iniciar y detener los listeners
def start_listeners():
    global mouse_listener, keyboard_listener
    # Crear y iniciar los listeners
    mouse_listener = mouse.Listener(on_move=on_move, on_click=on_click, on_scroll=on_scroll)
    keyboard_listener = keyboard.Listener(on_press=on_press, on_release=on_release)

    mouse_listener.start()
    keyboard_listener.start()

def stop_listeners():
    global mouse_listener, keyboard_listener
    if mouse_listener is not None:
        mouse_listener.stop()
    if keyboard_listener is not None:
        keyboard_listener.stop()

    # Exportar todos los eventos a un archivo
    with open("all_events.txt", "w") as file:
        for event in all_events:
            file.write(event + "\n")
    print("Todos los eventos se han guardado en 'all_events.txt'.")
    all_events.clear()
