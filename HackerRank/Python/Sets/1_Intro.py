# !/usr/bin/env python3
# utf-8
# https://www.hackerrank.com/challenges/py-introduction-to-sets/problem
# tag(s): implementación, estructuras de datos

def average(array):
    alturas_unicas = set(array)
    return sum(alturas_unicas) / len(alturas_unicas)

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    result = average(arr)
    print(result)
