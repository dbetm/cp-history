# !/usr/bin/env python3
# https://www.hackerrank.com/challenges/designer-door-mat/problem
# tag(s): strings, I/O
if __name__ == '__main__':
    n, m = map(int, input().split())
    n2 = int(n/2)
    m2 = m
    tr = ".|."
    trc = 1
    for i in range(n2):
        print("-"*int((m2-3)/2), end = '')
        print(tr*trc, end = '')
        print("-"*int((m2-3)/2))
        trc += 2
        m2 -= 6

    mid = m - 7
    print("-"*int(mid/2), end = '')
    print("WELCOME", end = '')
    print("-"*int(mid/2))

    trc -= 2
    m2 += 6
    for i in range(n2):
        print("-"*int((m2-3)/2), end = '')
        print(tr*trc, end = '')
        print("-"*int((m2-3)/2))
        trc -= 2
        m2 += 6
