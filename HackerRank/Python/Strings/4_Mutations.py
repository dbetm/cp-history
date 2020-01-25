# !/usr/bin/env python3

# https://www.hackerrank.com/challenges/python-mutations/problem
# tags: cadenas

def mutate_string(string, position, character):
    lista = list(string)
    lista[position] = character
    string = "".join(lista)
    return string

if __name__ == '__main__':
    s = input()
    i, c = input().split()
    s_new = mutate_string(s, int(i), c)
    print(s_new)
