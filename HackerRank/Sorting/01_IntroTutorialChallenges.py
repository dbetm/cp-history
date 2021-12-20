# https://www.hackerrank.com/challenges/tutorial-intro/problem
# Tag(s): binary search

from bisect import bisect_left


if __name__ == '__main__':
    v = int(input())
    n = int(input())

    arr = list(map(int, input().split()))

    print(bisect_left(arr, v))
