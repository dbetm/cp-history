# https://www.hackerrank.com/challenges/beautiful-pairs/problem
# tags: greedy, map

def solve(n: int, a: list, b: list) -> int:
    # store indexes of pairs
    left_set = set()
    right_set = set()
    count = 0

    for i in range(n):
        for j in range(n):
            if a[i] == b[j] and i not in left_set and j not in right_set:
                left_set.add(i)
                right_set.add(j)
                count += 1

    return count + 1 if count != n else count - 1


if __name__ == "__main__":
    n = int(input(""))

    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    print(solve(n, a, b))