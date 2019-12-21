# !/usr/bin/env python3

# https://www.hackerrank.com/challenges/python-string-split-and-join/problem
# tags: cadenas

def split_and_join(str):
    lista = str.split(" ")
    str = "-".join(lista)
    return str

if __name__ == '__main__':
    line = input()
    result = split_and_join(line)
    print(result)
