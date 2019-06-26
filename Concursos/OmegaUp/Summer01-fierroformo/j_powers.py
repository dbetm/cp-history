#!/usr/bin/env python
# -*- coding: utf-8 -*-
import math


num = int(raw_input())

sq_num = int(math.floor(math.sqrt(num))) + 1

pows = set([1])

if not 1 in pows:
    print ""

for i in xrange(2, sq_num):
    for j in xrange(2, sq_num):
        v = i ** j

        pows.add(v)

        if v > num or v * i > num:
            break


print len(pows)
