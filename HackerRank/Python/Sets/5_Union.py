# !/usr/bin/env python3
# utf-8
# https://www.hackerrank.com/challenges/py-set-union/problem
# tag(s): implementación, estructuras de datos

if __name__ == '__main__':
    n = int(input())
    english = set(map(int, input().split()))
    m = int(input())
    french = set(map(int, input().split()))
    ans = english.union(french)
    print(len(ans))
