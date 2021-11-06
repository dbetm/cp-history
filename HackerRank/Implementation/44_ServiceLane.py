# https://www.hackerrank.com/challenges/service-lane/problem
# Tag(s): Implementation

def compute(widths, i, j):
    ans = 4

    for x in range(i, j+1):
        ans = min(ans, widths[x])

        if ans == 1:
            break

    return ans


if __name__ == '__main__':
    n, t = list(map(int, input().split()))

    widths = list(map(int, input().split()))

    for _ in range(t):
        i, j = list(map(int, input().split()))
        print(compute(widths, i, j))
