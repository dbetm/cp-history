# 
# tags: sorting, implementation


def find_min(array, current_idx):
    """Find the minimum item of the subarray and return the index of it."""
    idx = current_idx
    min_item = array[current_idx]

    n = len(array)

    for jdx in range(idx + 1, n):
        if array[jdx] < min_item:
            min_item = array[jdx]
            idx = jdx

    return idx


def selectionSort(array):
    """My solution:
    Time: O(n^2)
    Space: O(1)
    """
    n = len(array)

    for idx in range(n):
        min_idx = find_min(array, idx)
        array[idx], array[min_idx] = array[min_idx], array[idx]

    return array


if __name__ == "__main__":  
    arr = list(map(int, input().split()))

    print(selectionSort(arr))
