# solved
# tags: binary-search, recursion, pointers


def solve(array, target, left_idx, right_idx):
    if left_idx > right_idx:
        return -1

    pivot = (right_idx + left_idx) // 2

    if array[pivot] == target:
        return pivot

    if array[pivot] < target:
        left_idx = pivot + 1
    else:
        right_idx = pivot - 1
    
    return solve(array, target, left_idx, right_idx)


def binarySearch(array, target):
    """My solution:
    Time: O(log(n))
    Space: O(1)
    """
    return solve(array, target, 0, len(array) - 1)


if __name__ == '__main__':
    arr = list(map(int, input().split()))
    target = int(input())

    print(binarySearch(arr, target))
