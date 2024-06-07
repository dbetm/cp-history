# solved
# tags: implementation


def threeNumberSort(array, order):
    """My solution
    Time: O(n)
    Space: O(1)
    """
    counter = {order[i]: 0 for i in range(3)}

    for num in array:
        counter[num] += 1

    idx = 0
    for num in order:
        for _ in range(counter[num]):
            array[idx] = num
            idx += 1

    return array


if __name__ == "__main__":
    arr = list(map(int, input().split()))
    order = list(map(int, input().split()))

    print(threeNumberSort(arr, order))
