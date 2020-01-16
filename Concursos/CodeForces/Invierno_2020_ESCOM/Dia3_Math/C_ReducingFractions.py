#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# tags: math, number theory

def gcd (a, b):
	if(b == 0):
		return a
	return gcd(b, a % b)


if __name__ == '__main__':
	num = 1
	deno = 1
	n,m = list(map(int,input().strip().split()))
	a = list(map(int,input().strip().split()))
	b = list(map(int,input().strip().split()))
	for i in range(n):
		num = num * a[i]
	for i in range(m):
		deno = deno * b[i]

	g = gcd(num, deno)
	num = int(num / g)
	deno = int(deno / g)

	print("1 1")
	print(num)
	print(deno)
