#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
# tag(s):

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    ans = 0

    for i in range(n):
        for j in range(i+1, n):
            ans = max([ans, arr[i] ^ arr[j]])

    print(ans)
