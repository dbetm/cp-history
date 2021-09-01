from collections import Counter

# https://www.hackerrank.com/challenges/collections-counter/problem

if __name__ == '__main__':
    x = int(input())
    prices = list(map(int, input().split()))
    prices_count = Counter(prices)

    earnings = 0

    n = int(input())
    for _ in range(n):
        shoe_size, x_i = list(map(int, input().split()))
        if prices_count[shoe_size]:
            earnings += x_i
            prices_count[shoe_size] = prices_count[shoe_size] - 1

    print(earnings)
