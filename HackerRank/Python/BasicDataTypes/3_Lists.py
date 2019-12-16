#!/usr/bin/env/ python3

# https://www.hackerrank.com/challenges/python-lists/problem
# tags: tipos de datos y estructuras, listas

if __name__ == '__main__':
    n = int(input())
    lista = []
    num = 0
    pos = 0
    for _ in range(n):
        cmd, *args = input().split()
        if(cmd == "insert"):
            pos, num = map(int, args)
            lista.insert(pos, num)
        elif(cmd == "print"):
            print(lista)
        elif(cmd == "remove"):
            num = int(args[0])
            lista.remove(num)
        elif(cmd == "append"):
            num = int(args[0])
            lista.append(num)
        elif(cmd == "sort"):
            lista.sort()
        elif(cmd == "pop"):
            lista.pop()
        else:
            lista.reverse()
