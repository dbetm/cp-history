# https://www.hackerrank.com/challenges/icecream-parlor/problem
# tags: search, map

def solve(money, costs) -> list:
    mapping = dict()
    ans = []

    for idx, cost in enumerate(costs):
        if cost >= money:
            continue

        if (money - cost) in mapping:
            ans.append(mapping[money - cost])
            ans.append(idx + 1)
            break

        mapping[cost] = idx + 1

    return ans


def print_list(l):

    for item in l:
        print(item, end=" ")
    print("")


if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        money = int(input())
        n = int(input())

        costs = list(map(int, input().split(" ")))

        print_list(solve(money, costs))
