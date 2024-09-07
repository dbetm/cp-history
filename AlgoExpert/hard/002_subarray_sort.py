# solved
# tags: arrays, implementation


def subarraySort(array):
    """My solution
    Time: O(n)
    Space: O(1)
    """
    n = len(array)
    ans = [-1, -1]

    for i in range(1, n):
        if array[i-1] > array[i]:
            # look for indices since the array is not sorted
            upper_idx = i
            right_min = array[i]
            ref = array[i-1]
            for j in range(i+1, n):
                if array[j] < ref:
                    upper_idx = j
                if array[j] >= ref:
                    ref = array[j]
                if array[j] < right_min:
                    right_min = array[j]

            lower_idx = i
            for k in range(i-1, -1, -1):
                if array[k] <= right_min:
                    break

                lower_idx = k

            ans = [lower_idx, upper_idx]
            break

    return ans


def subarraySort2(array):
    """Proposal
    Time: O(n)
    Space: O(1)
    """
    n = len(array)

    # The basic idea is to find the smallest and greatest number out of order
    max_num = float("-inf")
    min_num = float("inf")

    for i in range(n):
        # out of orders conditions
        c1 = i == 0 and array[i] > array[i+1]
        c2 = i > 0 and i < (n-1) and (array[i] < array[i-1] or array[i] > array[i+1])
        c3 = i == (n-1) and array[i] < array[i-1]

        if c1 or c2 or c3:
            if array[i] < min_num:
                min_num = array[i]
            if array[i] > max_num:
                max_num = array[i]
    
    # locate expected positions of max num and min num
    
    # first min_num
    lower_idx = -1
    idx = 0
    while idx < n:
        if array[idx] > min_num:
            lower_idx = idx
            break
        idx += 1

    upper_idx = -1
    idx = n-1
    while idx >= 0:
        if array[idx] < max_num:
            upper_idx = idx
            break

        idx -= 1

    return [lower_idx, upper_idx]


if __name__ == "__main__":
    arr = list(map(int, input().split()))

    print(subarraySort2(arr))
