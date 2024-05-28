# solved
# tags: math, dp, recursion


def compute(target, startingHand):
    if startingHand in dp:
        return dp[startingHand]
    elif startingHand >= (target-4) and startingHand <= target:
        return 0.0
    elif startingHand > target:
        return 1.0

    dp[startingHand] = 0.0

    for i in range(1, 11):
        dp[startingHand] += (0.1 * compute(target, startingHand + i))

    return dp[startingHand]


def blackjackProbability(target, startingHand):
    """My solution (watched hint)
    Time: O(target - starting hand)
    Space: O(target - starting hand)
    """
    global dp
    dp = dict()

    dp[startingHand] = compute(target, startingHand)

    return round(dp[startingHand], 3)


if __name__ == "__main__":
    target, starting_hand = list(map(int, input("").split(" ")))

    print(blackjackProbability(target, starting_hand))