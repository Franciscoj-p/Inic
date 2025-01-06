import threading
import tkinter as tk
import recording  # Importamos el archivo recording.py

# Funciones para iniciar y detener
def iniciar():
    print("Iniciando...")
    recording.start_listeners()  # Inicia los listeners
    button.config(text="Detener", command=detener)

def detener():
    print("Deteniendo...")
    
    def detener_y_notificar():
        recording.stop_listeners()  # Detiene los listeners
    
    # Ejecutar la detención en un hilo separado para no bloquear la interfaz
    threading.Thread(target=detener_y_notificar).start()
    button.config(text="Iniciar", command=iniciar)

# Crear la ventana principal
ventana = tk.Tk()
ventana.title("Botón Iniciar / Detener")
ventana.attributes("-topmost", True)

# Crear el botón
button = tk.Button(ventana, text="Iniciar", command=iniciar)
button.pack(pady=20, padx=20)

# Iniciar el loop de la ventana
ventana.mainloop()

