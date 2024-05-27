# solved
# tags: dp, recursion, implementation

dp = dict()


def compute(current_height: int, limit: int):
    if current_height < 0:
        return 0
    if current_height == 0:
        return 1

    if current_height in dp:
        return dp[current_height]

    ans = 0

    for i in range(1, limit+1):
        ans += compute(current_height - i, limit)

    dp[current_height] = ans

    return ans


def staircaseTraversal(height, maxSteps):
    """My solution
    Time: O(height)
    Space: O(height)
    """

    global dp
    dp = dict()

    compute(height, maxSteps)

    return dp[height]



if __name__ == "__main__":
    height, max_steps = list(map(int, input("").split(" ")))

    print(staircaseTraversal(height, max_steps))