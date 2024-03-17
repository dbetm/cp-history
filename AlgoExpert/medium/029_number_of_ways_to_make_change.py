# solved
# tags: dp, buttom-up

def numberOfWaysToMakeChange(n, denoms):
    """My solution
    Time: O(m * n)
    Space: O(n)

    Where m is the number of denominations and n the target.
    """
    if n == 0:
        return 1

    tmp = [0 for _ in range(n+1)]
    dp = [tmp, tmp]
    ans = 0
    top, down = 1, 0

    for denom in denoms:
        for j in range(1, n+1):
            dp[top][j] = dp[down][j]

            if j == denom:
                dp[top][j] += 1
            elif j - denom > 0:
                dp[top][j] += dp[top][j-denom]

        # swap indexes
        top, down = down, top
        ans = dp[top][-1]

    return ans


if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))

    print(numberOfWaysToMakeChange(n, arr))
