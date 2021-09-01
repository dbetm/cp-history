# !/usr/env/bin python3
# https://www.hackerrank.com/challenges/python-mod-divmod/problem

if __name__ == "__main__":
    a = int(input())
    b = int(input())

    res = divmod(a, b)
    print(res[0])
    print(res[1])
    print(res)
