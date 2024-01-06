# 
# tags: math, arrays


def nonConstructibleChange(coins):
    """Proposal
    Time: O(n log(n))
    Space: O(1)

    The essential idea is that we can always sum up to a k value
    while iterating the sorted coins array. And we will check if
    the k+1 amount is possible if the current coin is less than that.

    For example, when having:
    [1, 2, 4], we can sum up to 7
    1 => 1
    2 => 2
    3 => 1 + 2
    4 => 4
    5 => 4 + 1
    6 => 4 + 2 
    7 => 4 + 2 + 1

    if we want to sum up to 8, we need to add a coin which is less or equal than k+1, in this
    particular case 8, because if we add 9, then we can't create 8 in any way.
    """
    coins.sort()
    current_change = 0

    for coin in coins:
        if (current_change + 1) < coin:
            return current_change + 1

        current_change += coin

    return current_change + 1



if __name__ == "__main__":
    coins = list(map(int, input().rstrip().split(" ")))

    print(nonConstructibleChange(coins))