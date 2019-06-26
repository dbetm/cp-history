#!/usr/bin/env python
# -*- coding: utf-8 -*-
start, end = map(int, raw_input().split())


a = [i for i in xrange(start, end + 1) if ('{:b}'.format(i)).count('1') <= 4]

print len(a)
