# [True, True, True, False, False] # 60%
# 0      1     2     3
# [True, True, False] # 66.66%


# number_trues / len(build_run), O(n)


# binary search, O(log(n))


# [True, True, [True], False, False]

def binary_search(build_run: list, left: int, right: int, val: bool = False) -> int:
    # Time: O(log (n))
    # Space: O(log (n))
    if left > right:
        return -1

    mid = (left + right) // 2

    print(f"{mid=}", f"{build_run[mid]}")

    if build_run[mid] == val:
        if mid - 1 < 0:
            return 0
        elif build_run[mid-1] == (True if not val else False):
            return mid

        return binary_search(build_run, left, mid, val)

    return binary_search(build_run, mid+1, right, val)


if __name__ == "__main__":
    # true true false
    parse_to_boolean = lambda x: True if x == "true" else False
    sequence = list(map(parse_to_boolean, input().split(" ")))

    num_successful_runs = binary_search(sequence, 0, len(sequence)-1, False)

    if num_successful_runs == -1:
        print("no fails")
        perc = 100
    else:
        print(f"index of the first false: {num_successful_runs}")
        perc = (num_successful_runs / len(sequence)) * 100

    print(f"{perc=}")

