# TLE
#

s = []

def solve(left, right, dp):
    if left > right or right == len(dp):
        return -1001

    if dp[left][right] != -1002:
        return dp[left][right]

    lower_bound = 0 if left == 0 else s[left-1]

    ans = s[right] - lower_bound
    ans = max(
        ans,
        max(
            solve(left+1, right+1, dp),
            max(
                solve(left+1, right, dp),
                solve(left, right+1, dp)
            )
        )
    )

    dp[left][right] = ans

    return ans


def arrayMaxConsecutiveSum2(arr):
    s.append(arr[0])
    n = len(arr)

    for i in range(1, n):
        x = s[i-1] + arr[i]
        s.append(x)

    dp = [[-1002]*n for i in range(n)]

    ans = solve(0, 0, dp)

    return ans

if __name__ == '__main__':
    arr = list(map(int, input().split()))

    print(arrayMaxConsecutiveSum2(arr))
