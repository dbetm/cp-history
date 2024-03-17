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
    ans = 0
    down, top = 0, 1 # indexes to know that is the row to compute in dp[]

    print(dp)
    print("-------")

    for denom in denoms:
        # base cases
        dp[down][0] = 0
        dp[top][0] = -1

        for j in range(1, n+1):
            if j == denom:
                dp[top][j] = 1
            elif j < denom:
                dp[top][j] = dp[down][j]
            else:
                idx = j - denom
                if idx > 0 and dp[top][idx] != -1:
                    dp[top][j] = min2(dp[down][j], 1 + dp[top][j-denom])
                else:
                    dp[top][j] = dp[down][j]

        print(dp)
        ans = dp[top][-1]
        top, down = down, top

    return ans


if __name__ == "__main__":
    n = int(input())
    denoms = list(map(int, input().split()))

    print(minNumberOfCoinsForChange(n, denoms))
