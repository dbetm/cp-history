# solved
# tags: implementation, greedy


def compute(array):
    n = len(array)
    first_sum = 0
    second_sum = 0

    def next_idx(idx):
        if idx + 2 >= n:
            return idx + 2

        if idx + 4 < n:
            if (array[idx+2] + array[idx+4]) > array[idx+3]:
                return idx + 2
            else:
                return idx + 3
        elif idx + 3 < n:
            return idx+2 if array[idx+2] >= array[idx+3] else idx+3
        else:
            return idx+2

    # starting at index 0
    idx = 0
    while idx < n:
        first_sum += array[idx]

        idx = next_idx(idx)

    idx = 1
    # starting at index 1
    while idx < n:
        second_sum += array[idx]

        idx = next_idx(idx)

    return max(first_sum, second_sum)


def maxSubsetSumNoAdjacent(array):
    """My solution
    Time: O(n)
    Space: O(1) ? or O(n) - because reversing with slicing
    """
    return max(compute(array), compute(array[::-1]))


def maxSubsetSumNoAdjacent2(array):
    """Proposal
    - DP
    Time: O(n)
    Space: O(1)
    """
    ans = 0
    n = len(array)

    if n == 0:
        return ans
    if n == 1:
        return array[0]

    ai1 = array[0]
    ai2 = max(ai1, array[1])
    ans = ai2
    print(ans)

    for i in range(2, n):
        ans = max(ai2, ai1 + array[i])
        print(ans)
        ai1 = ai2
        ai2 = ans

    return ans


if __name__ == "__main__":
    arr = list(map(int, input().split()))

    print(maxSubsetSumNoAdjacent(arr))
    print(maxSubsetSumNoAdjacent2(arr))
