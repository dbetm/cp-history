# https://www.hackerrank.com/challenges/itertools-product/problem

from itertools import product

if __name__  == '__main__':
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    print(*product(A, B))
