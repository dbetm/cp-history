#!/usr/bin/env python
# -*- coding: utf-8 -*-
import math


def divisors(n):
    divs = [1]

    for i in xrange(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            divs.extend([i, n / i])

    divs.extend([n])

    return len(set(divs))


text = raw_input().upper()

n = 0
for c in text:
    n += ord(c)

print divisors(n)
