# solved
# tags: implementation, array


def fourNumberSum(array: list, targetSum):
    """My solution
    Time: O(n^3)
    Space: O(n)
    """
    array.sort()
    n = len(array)
    # initially all the numbers can be used
    nums_to_use = set(array)
    ans = list()

    for i in range(n):
        num_1 = array[i]
        for j in range(i+1, n):
            num_2 = array[j]
            for k in range(j+1, n):
                num_3 = array[k]

                num_4 = targetSum - num_1 - num_2 - num_3

                if num_4 in nums_to_use and num_4 > num_3:
                    ans.append([num_1, num_2, num_3, num_4])

        nums_to_use.remove(num_1)

    return ans


def fourNumberSum2(array: list, targetSum):
    """Proposal
    Time: Avg -> O(n^2), worst: O(n^3)
    Space: O(n^2)
    """
    p_pairs = dict()
    ans = list()
    n = len(array)

    for i in range(1, n):
        for j_after in range(i+1, n):
            q = array[i] + array[j_after]
            req_p = targetSum - q

            if req_p in p_pairs:
                for p in p_pairs[req_p]:
                    ans.append([p[0], p[1], array[i], array[j_after]])

        for j_before in range(0, i):
            sum_ = array[i] + array[j_before]
            if sum_ in p_pairs:
                p_pairs[sum_].append([array[i], array[j_before]])
            else:
                p_pairs[sum_] = [[array[i], array[j_before]]]

    return ans


if __name__ == "__main__":
    arr = list(map(int, input().split()))
    target_sum = int(input())

    print(fourNumberSum2(arr, target_sum))
