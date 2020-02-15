#!/usr/bin/env python
# -*- coding: utf-8 -*-

# https://www.hackerrank.com/challenges/itertools-permutations/problem
# tag(s): Implementación
from itertools import permutations


if __name__ == '__main__':
    str, k = input().split()
    k = int(k)
    permutaciones = sorted(list(permutations(str, k)))

    for per in permutaciones:
        print(*per, sep="")
