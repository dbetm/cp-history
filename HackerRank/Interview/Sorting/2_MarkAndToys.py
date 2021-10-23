# https://www.hackerrank.com/challenges/mark-and-toys/problem
# Tag(s): sorting, implementation


def maximumToys(prices, k):
    prices.sort()
    ans = 0

    for price in prices:
        if k - price < 0:
            break
        k -= price
        ans += 1

    return ans


if __name__ == '__main__':
    n, k = list(map(int, input().split()))
    prices = list(map(int, input().split()))

    print(maximumToys(prices, k))
