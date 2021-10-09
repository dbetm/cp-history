#
# Tag(s): 

def solve(coins, quantity, sums, sum, i):
    if i >= len(coins):
        return

    if sum in sums:
        return

    sums.add(sum)

    # not consider the current coin
    if (i+1) < len(coins):
        solve(coins, quantity, sums, sum + coins[i+1], i+1)

    for q in range(1, quantity[i]+1):
        solve(coins, quantity, sums, sum + coins[i] * q, i+1)


def possibleSums(coins, quantity):
    sums = set()

    solve(coins, quantity, sums, 0, 0)
    print(sums)

    return len(sums) - 1

if __name__ == '__main__':
    coins = list(map(int, input().split()))
    quantity = list(map(int, input().split()))

    print(possibleSums(coins, quantity))
