# https://www.hackerrank.com/challenges/chocolate-feast/problem
# Tag(s): Implementation

def chocolateFeast(n, c, m):
    chocos = n // c
    wrappers = chocos

    while True:
        aux = wrappers // m
        chocos += wrappers // m
        wrappers = wrappers % m + aux

        if aux <= 0:
            break

    return chocos


if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        n, c, m = list(map(int, input().split()))

        print(chocolateFeast(n, c, m))
