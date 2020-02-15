#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# https://www.hackerrank.com/challenges/itertools-combinations/problem
# tag(s): Implementación

from itertools import combinations

def displayPer(combinaciones):
    output = []
    for comb in combinaciones:
        comb = sorted(comb)
        output.append(comb)

    output = sorted(output)
    for comb in output:
        print(*comb, sep="")


if __name__ == '__main__':
    str, k = input().split()
    k = int(k)
    for i in range(1, k+1):
        displayPer(sorted(list(combinations(str, i))))
