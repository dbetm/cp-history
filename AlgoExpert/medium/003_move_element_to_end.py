# solved
# tags: pointers, implementation


def moveElementToEnd(array, toMove):
    """My solution:
    Time: O(n)
    Space: O(1)
    """
    left = 0
    right = len(array) - 1

    while left < right:
        if array[left] == toMove:
            if array[right] == toMove:
                right -= 1
            else:
                array[left], array[right] = array[right], array[left]
                left += 1
                right -= 1
        else:
            left += 1

    return array


if __name__ == "__main__":
    arr = list(map(int, input().split()))
    to_move = int(input())

    print(moveElementToEnd(arr, to_move))
