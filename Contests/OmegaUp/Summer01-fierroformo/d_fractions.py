#!/usr/bin/env python
# -*- coding: utf-8 -*-
a, b = map(int, raw_input().split())

mod = ""

if a % b > 0:
    mod = "{}/{}".format(a % b, b)

print (a // b), mod
