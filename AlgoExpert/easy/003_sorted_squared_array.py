# solved
# tags: arrays, pointers


def sortedSquaredArray(array):
    """My first solution
    Time: O(n * log(n))
    Space: O(n)
    """
    result = [item**2 for item in array]
    result.sort()

    return result


def sortedSquaredArray2(array):
    """My second solution
    Time: O(n)
    Space: O(n)
    -----Doesn't work
    """
    negatives = dict()
    idx = 0
    n = len(array)

    for _ in range(n):
        item = array[idx]
        if item >= 0:
            break

        item = abs(item)

        if item in negatives:
            negatives[item] += 1
        else:
            negatives[item] = 1

        idx += 1

    result = list()

    if idx == n:
        result = list(map(lambda x : x**2, negatives.keys()))

    for j in range(idx, n):
        item = array[j]

        result.append(item**2)

        if item in negatives:
            for _ in range(negatives[item]):
                result.append(item**2)

    return result


def sortedSquaredArray3(array):
    """Proposal
    Time: O(n)
    Space: O(n)
    """
    n = len(array)
    output = [0 for _ in range(n)]
    idx_to_insert = n - 1

    left = 0
    right = n - 1

    while left <= right:
        if array[left]**2 > array[right]**2:
            output[idx_to_insert] = array[left]**2
            left += 1
        else:
            output[idx_to_insert] = array[right]**2
            right -= 1
        
        idx_to_insert -= 1

    return output


if __name__ == "__main__":
    array = list(map(int, input().rstrip().split(" ")))

    print(sortedSquaredArray(array))
