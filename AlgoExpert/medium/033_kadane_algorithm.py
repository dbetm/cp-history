# solved
# tags: dp, implementation

# TODO:
# - check video


def kadanesAlgorithm(array):
    """My solution
    Time: O(n)
    Space: O(1)
    """
    dp = [array[0], 0]
    n = len(array)
    ans = dp[0]

    for i in range(1, n):
        if array[i-1] < 0:
            dp[1] = max(
                dp[0] + array[i-1] + array[i],
                array[i]
            )
        else:
            if array[i] < 0:
                dp[1] = dp[0]
            else:
                dp[1] = array[i] + dp[0]

        ans = max(ans, dp[1])
        dp[0] = dp[1]

    return ans


if __name__ == "__main__":
    arr = list(map(int, input().split()))

    print(kadanesAlgorithm(arr))
