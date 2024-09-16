# https://www.hackerrank.com/challenges/minimum-swaps-2
# tags: 


def min_swaps(arr: list) -> int:
    """My solution
    Time: O(n)
    Space: O(n)
    """
    swaps = 0
    elem_pos_map = {element: pos for pos, element in enumerate(arr)}

    # print(elem_pos_map)

    for idx in range(len(arr)):
        if arr[idx] == (idx+1):
            continue
        # index of element to swap
        jdx = elem_pos_map[idx+1]

        # update map
        elem_pos_map[idx+1] = idx
        elem_pos_map[arr[idx]] = jdx

        arr[idx], arr[jdx] = arr[jdx], arr[idx]
        swaps += 1

    return swaps



if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))

    print(min_swaps(arr))
