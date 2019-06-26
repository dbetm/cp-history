#!/usr/bin/env python
# -*- coding: utf-8 -*-
mm, nn = map(int, raw_input().split())


matrix = [map(int, raw_input().split()) for _ in xrange(mm)]


def minCost(cost, m, n):
    tc = [[0 for x in range(nn)] for x in xrange(mm)]

    tc[0][0] = cost[0][0]

    for i in xrange(1, m + 1):
        tc[i][0] = tc[i-1][0] + cost[i][0]

    for j in xrange(1, n + 1):
        tc[0][j] = tc[0][j-1] + cost[0][j]

    for i in xrange(1, m + 1):
        for j in xrange(1, n + 1):
            tc[i][j] = min(tc[i - 1][j], tc[i][j - 1]) + cost[i][j]

    return tc[m][n]


def min(x, y):
    return x if (x < y) else y


print minCost(matrix, mm - 1, nn - 1)
