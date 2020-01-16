# !/usr/bin/env python3
# https://www.hackerrank.com/challenges/python-string-formatting/problem
# tag(s):

def print_formatted(n):
    len_dec = len(str(n))
    len_oc = len("{0:o}".format(n))
    len_hex = len("{0:X}".format(n))
    len_bin = len("{0:b}".format(n))

    for i in range(1, n+1):
        dec = str(i)
        print(" "*(len_bin-len(dec)) + dec, end = ' ')
        oc = "{0:o}".format(i)
        print(" "*(len_bin-len(oc)) + oc, end = ' ')
        hex = "{0:X}".format(i)
        print(" "*(len_bin-len(hex)) + hex, end = ' ')
        bin = "{0:b}".format(i)
        print(" "*(len_bin-len(bin)) + bin)

if __name__ == '__main__':
    n = int(input())
    print_formatted(n)
