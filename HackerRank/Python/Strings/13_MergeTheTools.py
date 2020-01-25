# !/usr/bin/env python3
# https://www.hackerrank.com/challenges/merge-the-tools/problem
# tag(s): cadenas

def merge_the_tools(string, k):
    num_blocks = len(string) // k

    for i in range(num_blocks):
        dic = {}
        for x in range(i*k, k*(i+1)):
            dic[string[x]] = string[x]
            #print(string[x], end='')
        print(*dic.values(), sep='')

if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)
