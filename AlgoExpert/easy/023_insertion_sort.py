# solved
# tags: sorting, implementation


def insertionSort(array):
    """My solution

    The worst and average case:
    Time: O(n^2)
    Space: O(1)

    The best case:
    Time: O(n)
    Space: O(1)
    """
    n = len(array)

    for idx in range(1, n):
        jdx = idx

        while jdx > 0 and array[jdx] < array[jdx-1]:
            array[jdx-1], array[jdx] = array[jdx], array[jdx-1]
            jdx -= 1

    return array


if __name__ == '__main__':  
    arr = list(map(int, input().split()))

    print(insertionSort(arr))
