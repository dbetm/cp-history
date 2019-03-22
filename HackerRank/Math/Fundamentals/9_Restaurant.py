#!/bin/python3
import os
import sys
# https://www.hackerrank.com/challenges/restaurant/problem
def restaurant(l, b):
    greatestCommonDivisor = gcd(l, b)
    return (l/greatestCommonDivisor) * (b/greatestCommonDivisor)

def gcd(a, b):
    return gcd(b, a % b) if b else a;

if __name__ == '__main__':
    # número de casos
    t = int(input())

    for t_itr in range(t):
        lb = input().split()

        l = int(lb[0])
        b = int(lb[1])

        result = int(restaurant(l, b))
        print(result)
