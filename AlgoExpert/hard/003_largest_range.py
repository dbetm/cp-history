# solved
# tags: arrays, implementation, hashing


def largestRange(array: list):
    """My solution
    Time: O(n*log(n))
    Space: O(1) [sorting algo it could require O(n)]
    """
    array.sort()
    ans = [array[0], array[0]]
    start_num = array[0]
    end_num = array[0]
    max_len = 0
    current_len = 1
    n = len(array)

    for i in range(1, n):
        diff = array[i] - array[i-1]
        if diff == 1 or diff == 0:
            current_len += (1 if diff else 0)
            end_num = array[i]

            if i == (n-1) and max_len < current_len:
                ans = [start_num, end_num]
        else:
            if max_len < current_len:
                max_len = current_len
                ans = [start_num, end_num]

            current_len = 1
            start_num = array[i]
            end_num = array[i]

    return ans


def largestRange2(array: list):
    """Proposal
    Time: O(n)
    Space: O(n)
    """
    max_len = 0
    max_start_num = -1
    max_end_num = -1
    hash_table = {num: True for num in array}

    for num in array:
        if hash_table[num] == True:
            current_len = -1 # since we are counting two times the origin number
            # expand to left
            cursor = num
            while cursor in hash_table:
                hash_table[cursor] = False
                current_len += 1
                cursor -= 1
            start_num = cursor + 1

            # expand to right
            cursor = num
            while cursor in hash_table:
                hash_table[cursor] = False
                current_len += 1
                cursor += 1
            end_num = cursor - 1

            if current_len > max_len:
                max_len = current_len
                max_start_num = start_num
                max_end_num = end_num

    return [max_start_num, max_end_num]


if __name__ == "__main__":
    arr = list(map(int, input().split()))

    print(largestRange2(arr))
