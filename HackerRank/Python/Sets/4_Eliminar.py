# !/usr/bin/env python3
# utf-8
# https://www.hackerrank.com/challenges/py-set-discard-remove-pop/problem
# tag(s): implementación, estructuras de datos

def solve(s, num_ops):
    for i in range(num_ops):
        line = input().split()
        if(len(line) == 1 and len(s) > 0): #pop
            s.pop()
        else:
            op = line[0]
            num = int(line[1])
            if(op == 'remove' and num in s):
                s.remove(num)
            else:
                s.discard(num)
    return sum(s)

if __name__ == '__main__':
    n = int(input())
    s = set(map(int, input().split()))
    num_ops = int(input())
    print(solve(s, num_ops))
