# solved
# tags: implementation


def isMonotonic(array):
    """My solution:
    Time: O(n)
    Space: O(1)
    """
    if len(array) < 2:
        return True

    increasing = True
    decreasing = True

    for x in range(0, len(array) - 1):
        if array[x + 1] > array[x]:
            decreasing = False

        if array[x + 1] < array[x]:
            increasing = False

    return False if not decreasing and not increasing else True


if __name__ == "__main__":
    arr = list(map(int, input().split()))

    print(isMonotonic(arr))
