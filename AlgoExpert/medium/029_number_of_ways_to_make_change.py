# solved
# tags: dp, buttom-up

def numberOfWaysToMakeChange(n, denoms):
    """My solution
    Time: O(m * n)
    Space: O(1)

    Where m is the number of denominations and n the target.
    """
    if n == 0:
        return 1

    tmp = [0 for _ in range(n+1)]
    dp = [tmp, tmp]

    for denom in denoms:
        for j in range(1, n+1):
            dp[1][j] = dp[0][j]

            if j == denom:
                dp[1][j] += 1
            elif j - denom > 0:
                dp[1][j] += dp[1][j-denom]

        dp[0] = dp[1]

    return dp[1][-1]


if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))

    print(numberOfWaysToMakeChange(n, arr))
