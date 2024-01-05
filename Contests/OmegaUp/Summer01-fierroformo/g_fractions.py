#!/usr/bin/env python
# -*- coding: utf-8 -*-
from fractions import Fraction


ff = []
while True:
    try:
        line = raw_input()
        if not line:
            break
    except EOFError:
        break

    ff.append(map(int, line.split()))


res = Fraction()
for f in ff:
    res += Fraction(f[0], f[1])


print "{} / {}".format(res.numerator, res.denominator)
