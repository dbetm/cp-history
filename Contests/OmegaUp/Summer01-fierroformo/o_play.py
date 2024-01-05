#!/usr/bin/env python
# -*- coding: utf-8 -*-
n, k = map(int, raw_input().split())


i = 0
res = 0

for x in xrange(n - 1, 0, -1):
    i += 1

    if i > 2:
        break

    if x % k == k - 1:
        res = 1
        break


print res
print i
