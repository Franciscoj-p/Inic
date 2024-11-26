print('Dime tu nombre')
nombre = input()

print('Cuanto sacaste en matematica?')
nota_mate = float(input())

print('Cuanto sacaste en español?')
nota_espa = float(input())

print('Cuanto sacaste en ciencias?')
nota_cienc = float(input())

promed = (nota_mate + nota_espa + nota_cienc) / 3.0

if promed >= 6.0:
    print(f'Felicidades {nombre}, Aprobaste con un promedio de {promed}')
else:
    print(f'Lo siento mucho {nombre}, No aprobaste, tienes un promedio de {promed}')