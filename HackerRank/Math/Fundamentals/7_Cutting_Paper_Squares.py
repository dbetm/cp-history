#!/bin/python3
# https://www.hackerrank.com/challenges/p1-paper-cutting/problem?utm_campaign=social-buttons&utm_medium=twitter&utm_source=challenge
def getMinCuts(n, m):
    return (n*m) - 1

n, m = input().split()

print(getMinCuts(int(n),int(m)))
