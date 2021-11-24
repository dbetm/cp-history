from math import pow
# https://www.hackerrank.com/challenges/strange-code/problem
# Tag(s): Implementation, maths

def get_value(t):
    acc = 0 # time
    factor = 3
    i = 0

    while True:
        acc += 3 * pow(2, i)
        i += 1

        if acc >= t:
            break

        factor *= 2

    return int(acc - t) + 1

""" Alternative:
s = int(log2((t-1) // 3+1))
a , b = 3*(2**s-1)+1, 3*2**s
print(a + b - t)
"""


if __name__ == '__main__':
    t = int(input())

    print(get_value(t))
