# solved
# tags: implementation, set, pointers


def threeNumberSum(array, targetSum):
    """My solution:
    Time: O(n^2)
    Space: O(n)
    """
    ans = list()
    nums_set = set(array)
    n = len(array)
    array.sort()

    for idx in range(n):
        a = array[idx]

        for jdx in range(idx+1, n):
            b = array[jdx]

            if b in nums_set:
                c = targetSum - a - b
                if c in nums_set and c > b:
                    ans.append([a, b, c])

        nums_set.remove(a)

    return ans


if __name__ == "__main__":
    arr = list(map(int, input().split()))
    target = int(input())

    print(threeNumberSum(arr, target))
