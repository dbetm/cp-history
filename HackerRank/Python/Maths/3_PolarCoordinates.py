# !/usr/bin/env python3
# https://www.hackerrank.com/challenges/polar-coordinates/problem
import cmath as cm

if __name__ == "__main__":
    z = complex(input())
    print(abs(z))
    print(cm.phase(z))
