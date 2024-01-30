# solved
# tags: implementation

# TODO:
# - try to solve in constant space
# - watch video explanation for longest peak

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


if __name__ == "__main__":
    arr = list(map(int, input().split()))

    print(firstDuplicateValue(arr))
