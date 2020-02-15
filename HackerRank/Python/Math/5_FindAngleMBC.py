#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# https://www.hackerrank.com/challenges/find-angle/problem
import math

if __name__ == "__main__":
    ab = int(input())
    bc = int(input())

    res_radians = math.atan2(ab, bc)
    res_degrees = int(round(math.degrees(res_radians)))

    print(str(res_degrees) + "°")
