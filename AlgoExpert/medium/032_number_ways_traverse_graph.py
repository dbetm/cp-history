# solved
# tags: dp, bottom-up


def numberOfWaysToTraverseGraph(width, height):
    """My solution:
    Time: O(n*m)
    Space: O(min(n, m))
    """
    min_side = width if width <= height else height
    max_side = width if width > height else height

    dp = [ [0 for _ in range(min_side)] for _ in range(2)]
    dp[0][0] = 1

    n = max_side
    m = min_side
    # index to switch, is to optimize since only two rows are necessary
    top, down = 1, 0
    ans = 1

    for _ in range(n):
        dp[top][0] = 1
        for j in range(1, m):
            dp[top][j] = dp[top][j-1] + dp[down][j]

        ans = dp[top][-1]
        top, down = down, top

    return ans


if __name__ == "__main__":
    height, width = list(map(int, input("").split(" ")))

    print(numberOfWaysToTraverseGraph(width, height))
