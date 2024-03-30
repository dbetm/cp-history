import math

MINUTES_IN_FOUR_HOURS = 240

# https://codeforces.com/problemset/problem/750/A
# tags: math


def solve_quadratic_eq(a: float, b: float, c: float) -> float:
    """Return the positive squared root if exists."""
    rad = b**2 - 4*a*c

    if rad < 0:
        raise Exception
    
    rad = math.sqrt(rad)

    n1 = (-b + rad) / (2 * a)
    n2 = (-b - rad) / (2 * a)

    if n1 >= 0:
        return n1

    return n2


if __name__ == "__main__":
    n, k = list(map(int, input("").split(" ")))

    available_mins = MINUTES_IN_FOUR_HOURS - k

    ans = int(solve_quadratic_eq(a=1, b=-1, c=float(-2*available_mins) / 5) - 1)

    print(min(ans, n))