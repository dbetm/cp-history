# solved
# tags: implementation, array, pointers


def twoNumberSum(array, targetSum):
    """My implementation
    Time: O(nlog(n))
    Memory: O(1)
    
    """
    array.sort()

    left = 0
    right = len(array) - 1

    while left < right:
        if (array[left] + array[right]) == targetSum:
            return [array[left], array[right]]
        elif (array[left] + array[right]) > targetSum:
            right -= 1
        else:
            left += 1

    return []


def twoNumberSum2(array, targetSum):
    """Proposal
    Time: O(n)
    Memory: O(n)
    
    """
    array_set = set(array)

    for x in array_set:
        y = targetSum - x

        if y in array_set:
            return [min(x, y), max(x, y)]

    return []



if __name__ == "__main__":
    array = list(map(int, input().split(" ")))
    target = int(input())

    print(twoNumberSum2(array, target))
