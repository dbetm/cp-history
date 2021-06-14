# https://www.hackerrank.com/challenges/py-check-strict-superset/problem

def is_strict_superset(a, x):
    return x.issubset(a) and len(a.difference(x)) >= 1


if __name__ == '__main__':
    a = set(map(int, input().split()))
    n = int(input())

    flag = True

    for i in range(n):
        x = set(map(int, input().split()))

        flag = is_strict_superset(a, x) and flag

    print(flag)
