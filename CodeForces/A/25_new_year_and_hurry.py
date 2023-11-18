MINUTES_IN_FOUR_HOURS = 240


if __name__ == "__main__":
    n, k = list(map(int, input("").split(" ")))

    available_mins = MINUTES_IN_FOUR_HOURS - k

    for i in range(1, n):
        pass # not use loop, use quadratic formula