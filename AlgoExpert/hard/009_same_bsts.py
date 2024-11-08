# solved
# tags: recursion, binary-search, bst


def sameBsts(arrayOne, arrayTwo):
    """My solution (checked hint)
    Time: O(n^2)
    Space: O(d) 
    d as depth
    """
    if len(arrayOne) != len(arrayTwo):
        return False

    if len(arrayOne) == 0 and len(arrayTwo) == 0:
        return True

    if arrayOne[0] != arrayTwo[0]:
        return False

    array_one_left = list()
    array_one_right = list()
    array_two_left = list()
    array_two_right = list()

    for idx in range(1, len(arrayOne)):
        if arrayOne[idx] < arrayOne[0]:
            array_one_left.append(arrayOne[idx])
        else:
            array_one_right.append(arrayOne[idx])

        if arrayTwo[idx] < arrayTwo[0]:
            array_two_left.append(arrayTwo[idx])
        else:
            array_two_right.append(arrayTwo[idx])

    return sameBsts(array_one_left, array_two_left) and sameBsts(array_one_right, array_two_right)


if __name__ == "__main__":
    array_1 = list(map(int, input().split(" ")))
    array_2 = list(map(int, input().split(" ")))

    print(sameBsts(array_1, array_2))

