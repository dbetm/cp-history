# https://codeforces.com/problemset/problem/1351/B
# tag(s): geometry, implementation

def wasSquare(a1, b1, a2, b2):
    ans = 'NO'

    if a1 == a2 and (b1 + b2) == a1:
        ans = 'YES'
    elif a1 == b2 and (a2 + b1) == a1:
        ans = 'YES'
    elif b1 == a2 and (a1 + b2) == a2:
        ans = 'YES'
    elif b1 == b2 and (a1 + a2) == b1:
        ans = 'YES'

    return ans

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        a1, b1 = list(map(int, input().split()))
        a2, b2 = list(map(int, input().split()))

        print(wasSquare(a1, b1, a2, b2))
