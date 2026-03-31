# https://www.hackerrank.com/challenges/greedy-florist/problem
# tags: sorting, implementation, greedy


def get_min_cost(prices: list, num_friends: int) -> int:
    # sort in ascending order
    prices.sort()
    total_cost = 0
    num_purchases_by_friend = [0 for _ in range(num_friends)]
    idx_friend = 0

    while len(prices) > 0:
        total_cost += (num_purchases_by_friend[idx_friend] + 1) * prices.pop()
        num_purchases_by_friend[idx_friend] += 1
        idx_friend = (idx_friend + 1) % num_friends

    return total_cost


if __name__ == '__main__':

    num_flowers, num_friends = tuple(map(int, input().split(" ")))

    base_prices = list(map(int, input().split(" ")))

    print(get_min_cost(base_prices, num_friends))


