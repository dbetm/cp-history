import math
import os
import random
import re
import sys

# https://www.hackerrank.com/challenges/battery/problem

if __name__ == '__main__':
    timeCharged = float(input().strip())

    ans = 8.00 if timeCharged >= 4.0 else timeCharged * 2.0

    print('{:.2f}'.format(ans))
