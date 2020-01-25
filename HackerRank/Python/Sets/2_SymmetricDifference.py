# !/usr/bin/env python3
# utf-8
# https://www.hackerrank.com/challenges/symmetric-difference/problem
# tag(s): implementación, estructuras de datos

def symmetric_diference(a, b):
    c = a.difference(b)
    c2 = b.difference(a)
    c.update(list(c2))
    c_list = list(c)
    c_list.sort()
    print(*c_list, sep='\n')

if __name__ == '__main__':
    m = int(input())
    a = list(map(int, input().split()))
    n = int(input())
    b = list(map(int, input().split()))
    symmetric_diference(set(a), set(b))
