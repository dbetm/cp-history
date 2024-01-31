# solved
# tags: implementation


def firstDuplicateValue(array):
    """My solution:
    Time: O(n)
    Space: O(n)
    """
    passed_values = set()

    for value in array:
        if value in passed_values:
            return value

        passed_values.add(value)

    return -1


def firstDuplicateValue2(array):
    """Proposal based on the hints:
    Time: O(n)
    Space: O(1)

    It's a creative way to store two data points at each index.
    """
    ans = -1

    for idx in range(len(array)):
        val = abs(array[idx])

        if array[val-1] < 0:
            ans = val
            break

        array[val-1] *= -1

    return ans


if __name__ == "__main__":
    arr = list(map(int, input().split()))

    print(firstDuplicateValue(arr))
    print(firstDuplicateValue2(arr))
