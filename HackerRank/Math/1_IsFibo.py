#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# https://www.hackerrank.com/contests/codesprint5/challenges/is-fibo/problem
# tag(s): Math
import math

def isSquare(y):
    root = int(math.sqrt(y))
    return (root*root == y)

""" A number is Fibonacci if and only if one or both of (5*n²+4) or (5*n²-4) is
a perfect square.
"""
def isFibo(n):
    x = 5 * (n * n)
    y1 = x + 4
    y2 = x - 4

    return (isSquare(y1) or isSquare(y2))


if __name__ == '__main__':
    t = int(input())

    for i in range(t):
        n = int(input())
        if(isFibo(n)):
            print("IsFibo")
        else:
            print("IsNotFibo")
