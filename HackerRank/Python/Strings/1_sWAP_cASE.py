# !/usr/bin/env python3

# https://www.hackerrank.com/challenges/swap-case/problem
# tags: cadenas

def swap_case(str):
    res = ""
    for c in str:
        if(c >= 'A' and c <= 'Z'):
            res += c.lower()
        elif(c >= 'a' and c <= 'z'):
            res += c.upper()
        else:
            res += c
    return res

if __name__ == '__main__':
    s = input()
    result = swap_case(s)
    print(result)
