# !/usr/bin/env python3
# utf-8
# https://www.hackerrank.com/challenges/py-set-add/problem
# tag(s): implementación, estructuras de datos

def solve(n):
    conjunto = set()
    for i in range(n):
        pais = input()
        conjunto.add(pais)
    return len(conjunto)

if __name__ == '__main__':
    n = int(input())
    print(solve(n))
