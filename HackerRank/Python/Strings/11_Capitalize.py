# !/usr/bin/env python3
# https://www.hackerrank.com/challenges/capitalize/problem

if __name__ == '__main__':
    s = list(input().split())

    for str in s:
        print(str.capitalize(), end =' ')
    print()
