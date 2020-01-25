# !/usr/bin/env python3
# utf-8
# https://www.hackerrank.com/challenges/py-set-intersection-operation/problem
# tag(s): implementación, estructuras de datos

if __name__ == '__main__':
    n = int(input())
    english = set(map(int, input().split()))
    m = int(input())
    french = set(map(int, input().split()))
    ans = english.intersection(french)
    print(len(ans))
