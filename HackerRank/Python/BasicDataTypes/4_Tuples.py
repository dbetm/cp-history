#!/usr/bin/env python3

# https://www.hackerrank.com/challenges/python-tuples/problem
# tags: tipos de datos y estructuras de datos, tuplas

if __name__ == '__main__':
    n = int(input())
    lista = map(int, input().split())
    tupla = tuple(lista)
    print(hash(tupla))
