#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# TLE on test 2
# tag(s): math, brute force
import math

max = 1000000007
a = '0'
b = '0'

def is_excellent(x):
    ans = True
    sum_digs = 0

    x = str(x)

    for dig in x:
        if(dig != a and dig != b):
            ans = False
            break;
        sum_digs += int(dig)

    if(ans):
        x = str(sum_digs)

        for dig in x:
            if(dig != a and dig != b):
                ans = False
                break;

    return ans


def count_excellent_numbers(n):
    n = int(n)
    inicio = int(math.pow(10, n-1))
    final = inicio * 10
    #print(inicio)
    #print(final)
    cont = 0
    i = inicio

    while(i < final):
        aux = str(i)[0]
        #print(i, aux)
        if(aux != a and aux != b):
            i += inicio
            continue
        if(is_excellent(i)):
            cont = (cont + 1) % max
        i += 1

    return cont

if __name__ == '__main__':
    a, b, n = input().split()

    print(count_excellent_numbers(n))
