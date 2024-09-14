# solved
# tags: dp, recursion
from collections import defaultdict



def throw(dice: int, numSides: int, target: int) -> int:
    if dice < 1:
        return 0 if target != 0 else 1

    if target <= 0:
        return 0

    if dp[dice][target] != -1:
        return dp[dice][target]

    perm = 0
    for side in range(1, numSides + 1):
        x = target - side
        perm += throw(dice - 1, numSides, x)

    dp[dice][target] = perm
    return dp[dice][target]


def diceThrows(numDice, numSides, target):
    """My solution
    Time: O(numDice * numSides * target)
    Space: O(numDice * target)
    """
    global dp
    # dp = [[-1] * (target + 1) for _ in range(numDice + 1)]
    dp = [defaultdict(lambda: -1) for _ in range(numDice + 1)]

    return throw(numDice, numSides, target)



def diceThrows2(numDice, numSides, target):
    """Proposal - using DP with bottom up approach
    Time: O(numDice * numSides * target)
    Space: O(target)
    """
    # if we have 0 throws and target > 0, then the naive answer is 0
    dp = [[0] * (target + 1) for _ in range(2)]
    # when having 0 throws and 0 as target, then the answer is 1
    dp[0][0] = 1
    idx_past_r = 0 # this will toggle, in the dp of size 2, with this we reduce the space complexity
    current_idx = 1

    for _ in range(1, numDice + 1):
        current_target = 0

        while current_target <= target:
            permutations = 0

            for side in range(1, numSides + 1):
                if current_target - side >= 0:
                    permutations += dp[idx_past_r][current_target-side]

            dp[current_idx][current_target] = permutations

            current_target += 1

        # toggle idx_past_row
        current_idx, idx_past_r = idx_past_r, current_idx

    print(dp)

    return dp[idx_past_r][target]


if __name__ == "__main__":
    dices, sides, target = list(map(int, input().split()))

    print(diceThrows2(dices, sides, target))

    # print(dp)