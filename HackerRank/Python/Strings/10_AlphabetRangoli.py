# !/usr/bin/env python3
# https://www.hackerrank.com/challenges/alphabet-rangoli/problem
def print_rangoli(size):
    rem = 4*size - 3
    rem -= 1
    for i in range(size):
        print("-"*(rem // 2), end='')
        for x in map(chr, range(size+96, size+96-i-1, -1)):
            if(i == 0):
                print(x, end='')
            else:
                print(x, end='-')
        l = size+96-i+1
        for x in map(chr, range(size+96-i+1, size+96+1)):
            if(l == size + 96):
                print(x, end='')
            else:
                print(x, end='-')
            l += 1
        print("-"*(rem // 2))
        rem -= 4

    rem = 4
    for i in range(size-2, -1, -1):
        print("-"*(rem // 2), end='')
        for x in map(chr, range(size+96, size+96-i-1, -1)):
            if(i == 0):
                print(x, end='')
            else:
                print(x, end='-')
        l = size+96-i+1
        for x in map(chr, range(size+96-i+1, size+96+1)):
            if(l == size + 96):
                print(x, end='')
            else:
                print(x, end='-')
            l += 1
        print("-"*(rem // 2))
        rem += 4

if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)
