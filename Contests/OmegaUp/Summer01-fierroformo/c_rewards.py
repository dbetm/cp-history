#!/usr/bin/env python
# -*- coding: utf-8 -*-
num = int(raw_input())

x = 5
y = 7

rewards = ((num // x) + (num // y)) - (num // (x * y))

print rewards
