# https://www.hackerrank.com/challenges/py-check-subset/problem

def is_subset(a, b):
    return len(a.difference(b)) == 0

if __name__ == '__main__':
    t = int(input())

    for i in range(t):
        n = int(input())
        a = set(map(int, input().split()))

        n = int(input())
        b = set(map(int, input().split()))

        print(is_subset(a, b))
