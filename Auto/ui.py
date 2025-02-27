import threading
import tkinter as tk
import recording  # Importamos el archivo recording.py
import running  # Importamos el archivo running.py
import os  # Para verificar si el archivo existe

# Funciones para iniciar y detener grabación
def iniciar():
    print("Iniciando grabación...")
    recording.start_listeners()  # Inicia los listeners
    button.config(text="Detener Grabación", command=detener)
    buttonRep.config(state=tk.DISABLED)  # Deshabilita el botón de reproducción

def detener():
    print("Deteniendo grabación...")
    
    def detener_y_notificar():
        recording.stop_listeners()  # Detiene los listeners
    
    # Ejecutar la detención en un hilo separado para no bloquear la interfaz
    threading.Thread(target=detener_y_notificar).start()
    button.config(text="Iniciar Grabación", command=iniciar)
    buttonRep.config(state=tk.NORMAL)  # Habilita el botón de reproducción

# Funciones para iniciar y detener reproducción
def iniciar_rep():
    print("Iniciando reproducción...")
    
    running.bucle_infinito = var_bucle_infinito.get()  # Controla el bucle infinito desde el checkbox
    buttonRep.config(text="Detener Reproducción", command=detener_rep)
    button.config(state=tk.DISABLED)  # Deshabilita el botón de grabación

    # Iniciar la reproducción en un hilo separado
    threading.Thread(target=running.ejecutar_eventos, daemon=True).start()

def detener_rep():
    print("Deteniendo reproducción...")
    
    def detener_y_notificar_rep():
        running.detener_reproduccion()  # Detiene la reproducción de eventos
    
    # Ejecutar la detención en un hilo separado para no bloquear la interfaz
    threading.Thread(target=detener_y_notificar_rep).start()
    buttonRep.config(text="Iniciar Reproducción", command=iniciar_rep)
    button.config(state=tk.NORMAL)  # Habilita el botón de grabación

# Crear la ventana principal
ventana = tk.Tk()
ventana.title("Botón Iniciar / Detener")
ventana.attributes("-topmost", True)

# Crear el botón de grabación
button = tk.Button(ventana, text="Iniciar Grabación", command=iniciar)
button.pack(pady=20, padx=20)

# Crear el botón de reproducción
buttonRep = tk.Button(ventana, text="Iniciar Reproducción", command=iniciar_rep)
buttonRep.pack(pady=20, padx=20)

# Crear el checkbox para elegir entre bucle infinito o una sola ejecución
var_bucle_infinito = tk.BooleanVar()
checkbox_bucle = tk.Checkbutton(ventana, text="Ejecutar en bucle infinito", variable=var_bucle_infinito)
checkbox_bucle.pack(pady=20, padx=20)

# Iniciar el loop de la ventana
ventana.mainloop()
