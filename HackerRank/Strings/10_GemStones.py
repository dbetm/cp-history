# https://www.hackerrank.com/challenges/gem-stones/problem
# Tag(s): sets, strings

if __name__ == '__main__':
    n = int(input())

    a = set(input())

    for i in range(n-1):
        x = set(input())
        a = a.intersection(x)

    print(len(a))
