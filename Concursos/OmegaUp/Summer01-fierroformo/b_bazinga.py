#!/usr/bin/env python
# -*- coding: utf-8 -*-
n = int(raw_input())

names = []


for i in xrange(n):
    item = raw_input().split()
    names.append({'name': item[0], 'age': int(item[1]), 'hobby': item[2]})


for item in sorted(names, key=lambda k: k['age'], reverse=True):
    print item['name'], item['age'], item['hobby']
