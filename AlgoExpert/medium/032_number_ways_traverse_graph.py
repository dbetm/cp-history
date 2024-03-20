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


def numberOfWaysToTraverseGraph2(width, height):
    """Proposal
    Time: O(n + m)
    Space: O(1)

    Using permutations, we need to make width-1 right (R) and height-1 down (D) 
    movements to reach out the right bottom corner, so we can use this formula:

    (R + D)! / R! * D!

    Where n is the height and m is the width
    """
    r = width - 1
    d = height - 1
    r_fact = 1
    d_fact = 1
    total = 1

    # compute factorial
    for i in range(1, r+d+1):
        total *= i
        if i == r:
            r_fact = total
        if i == d:
            d_fact = total

    print(r_fact, d_fact, total)

    return total // (r_fact * d_fact)


if __name__ == "__main__":
    height, width = list(map(int, input("").split(" ")))

    print(numberOfWaysToTraverseGraph2(width, height))
