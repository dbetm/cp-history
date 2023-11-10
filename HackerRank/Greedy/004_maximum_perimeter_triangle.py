from typing import Optional

# https://www.hackerrank.com/challenges/maximum-perimeter-triangle/problem
# tags: math, greedy, implementation


def is_valid_triplet(a: int, b: int, c: int) -> bool:
    """Check of the given triplet is valid to create a non-degenerated triangle.
    So, always you have two sides which sum is greater to the another side.
    """
    return (
        a + b > c and
        a + c > b and
        b + c > a
    )


def is_better_triplet(base: Optional[tuple], new: tuple) -> bool:
    """it's a better triplet when the minimum size is greater than the minimum of
    the base triple."""
    if not base:
        return True
    
    max_base = max(base[0], max(base[1], base[2]))
    max_new = max(new[0], max(new[1], new[2]))

    min_base = min(base[0], min(base[1], base[2]))
    min_new = min(new[0], min(new[1], new[2]))

    return min_new > min_base and max_new >= max_base


def solve(n: int, sticks: list) -> list:
    sticks.sort(reverse=True)
    triplet = None

    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                a, b, c = sticks[i], sticks[j], sticks[k]

                if is_valid_triplet(a, b, c):
                    if is_better_triplet(base=triplet, new=(a, b, c)):
                        triplet = (a, b, c)

    if not triplet:
        return [-1]

    ans = list(triplet)
    ans.sort()

    return ans


def print_list(l):

    for item in l:
        print(item, end=" ")
    print("")


if __name__ == "__main__":
    n = int(input(""))
    sticks = list(map(int, input().split(" ")))

    print_list(solve(n, sticks))