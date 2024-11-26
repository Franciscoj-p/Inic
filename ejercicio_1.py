print('Dime tu nombre')
nombre = input()

print('Cuantas materias vas a promediar?')
cantidad_materias = int(input())

notas = {}
for i in range(cantidad_materias):
    nombre_materia = input(f"Ingresa el nombre de la materia {i + 1}: ")
    calificacion = float(input(f"Ingresa la calificación de {nombre_materia}: "))
    notas[nombre_materia] = calificacion  # Agregar al diccionario nombre_materia es la key y calificacion el valor
    
promedio = sum(notas.values()) / len(notas)  #.values devuelve todos los valores

if promedio >= 6.0:
    print(f'Felicidades {nombre}, Aprobaste con un promedio de {promedio:.1f}') #:.1f limita los decimales a 1
else:
    print(f'Lo siento mucho {nombre}, No aprobaste, tienes un promedio de {promedio:.1f}')
    
    print("\nCalificaciones ingresadas:")
for materia, calificacion in notas.items(): #almacena en materia, calificacion los pares ordenados que devuelve .items desde el diccionario notas
    print(f"{materia}: {calificacion}")

print(f"\nEl promedio de tus notas es: {promedio:.2f}")