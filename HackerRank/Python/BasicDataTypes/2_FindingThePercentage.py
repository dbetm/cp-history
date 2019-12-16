#!/usr/bin/env python3

# https://www.hackerrank.com/challenges/finding-the-percentage/problem
# tags: tipos de datos y estructuras de datos, diccionario

if __name__ == '__main__':
    n = int(input())
    estudiantes = {} # crear el diccionario
    for _ in range(n):
        # leemos el nombre y las calis como cadenas
        # con el asterisco es para leer el resto de cadenas resultantes del split
        nombre, *calis = input().split()
        # parseamos las calis a float
        calis = list(map(float, calis))
        # agregamos el estudiante al diccionario
        estudiantes[nombre] = calis
    # leemos el nombre del alumno a consultar
    query_name = input()
    calificaciones = estudiantes[query_name]
    suma = 0.0
    for c in calificaciones:
        suma += c
    promedio = suma / 3.0
    print("%.2f" % promedio)
