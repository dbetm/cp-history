# https://www.hackerrank.com/challenges/sherlock-and-array/problem
# tags: search, interval, map


def solve(n: int, arr: list) -> str:
    left = dict()

    if n == 1:
        return "YES"

    left[0] = 0
    left[1] = arr[0]

    for idx in range(2, n-1):
        left[idx] = left[idx-1] + arr[idx-1]

    right = arr[-1]
    for idx in range(n-2, -1, -1):
        if right == left[idx]:
            return "YES"

        right += arr[idx]
    
    return "NO"


if __name__ == "__main__":
    test_cases = int(input())

    for _ in range(test_cases):
        n = int(input())
        arr = list(map(int, input().rstrip().split(" ")))

        print(solve(n, arr))
