# solved
# tags: sorting, implementation


def bubbleSort(array):
    """ My solution
    Time: O(n^2)
    Space: O(1)
    """
    n = len(array)

    for idx in range(0, n):
        for jdx in range(idx+1, n):
            if array[jdx] < array[idx]:
                array[idx], array[jdx] = array[jdx], array[idx]

    return array


def bubbleSort2(array):
    """ Proposal

    The worst and average case:
    Time: O(n^2)
    Space: O(1)

    The best case:
    Time: O(n)
    Space: O(1)
    """
    n = len(array)

    for idx in range(0, n - 1):
        has_swapped = False
        for jdx in range(0, n - idx - 1):
            if array[jdx] >  array[jdx+1]:
                has_swapped = True

                array[jdx], array[jdx+1] = array[jdx+1], array[jdx]

        if not has_swapped:
            break

    return array


if __name__ == '__main__':  
    arr = list(map(int, input().split()))

    print(bubbleSort(arr))
    print(bubbleSort2(arr))
