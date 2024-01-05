#!/usr/bin/env python
# -*- coding: utf-8 -*-
t, n = map(int, raw_input().split())

points = map(int, (raw_input() for _ in xrange(n)))
points.append(0)

points = sorted(points, key=abs)

suma = 0

for i in xrange(len(points) - 1):
    r = abs(points[i] - points[i + 1])
    if suma + r > t:
        print i
        break

    suma += r
