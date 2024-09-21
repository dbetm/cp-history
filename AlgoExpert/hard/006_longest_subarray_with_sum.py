# solved
# tags: cursors, arrays, implementation



def longestSubarrayWithSum(array, target):
    """My solution
    Time: O(n)
    Space: O(1)
    """
    n = len(array)

    if n == 0:
        return []

    left = 0
    right = 0
    current_sum = array[0]
    longest_arr_idxs = []
    longest_len = -1

    while left < n or right < n:
        # print(f"{left=}", f"{right=}")
        if current_sum == target:
            len_ = right - left + 1
            if longest_len == -1 or longest_len < len_:
                longest_len = len_
                longest_arr_idxs = [left, right]
            right += 1
            if right < n:
                current_sum += array[right]
            else:
                current_sum -= array[left]
                left += 1
        elif current_sum > target:
            current_sum -= array[left]
            left += 1
            if right < left:
                right = left
                if right < n:
                    current_sum = array[right]
        else:
            right += 1
            if right < n:
                current_sum += array[right]
            else:
                break

    return longest_arr_idxs



if __name__ == "__main__":
    target = int(input())
    arr = list(map(int, input().split()))

    print(longestSubarrayWithSum(arr, target))
