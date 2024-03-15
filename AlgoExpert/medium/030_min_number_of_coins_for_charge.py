# solved
# tags: dp, bottom-up


def min2(a, b):
    if a == -1:
        return b
    if b == -1:
        return a

    if a < b:
        return a

    return b


def minNumberOfCoinsForChange(n, denoms):
    """My solution
    Time: O(n*m)
    Space: O(n)

    Where n is the target and m is the different values of denoms given.
    """
    if n == 0:
        return 0

    dp = [[-1 for _ in range(0, n+1)], [0 for _ in range(0, n+1)]]
    dp[0][0] = 0
    dp[1][0] = -1

    print(dp)
    print("-------")

    for denom in denoms:
        for j in range(1, n+1):
            if j == denom:
                dp[1][j] = 1
            elif j < denom:
                dp[1][j] = dp[0][j]
            else:
                idx = j - denom
                if idx > 0 and dp[1][idx] != -1:
                    dp[1][j] = min2(dp[0][j], 1 + dp[1][j-denom])
                else:
                    dp[1][j] = dp[0][j]

        print(dp)

        dp[0] = dp[1]

    return dp[1][-1]


if __name__ == "__main__":
    n = int(input())
    denoms = list(map(int, input().split()))

    print(minNumberOfCoinsForChange(n, denoms))
