# https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem
# tags: arrays, implementation


def rot_left(rotations, array):
    """
    Time: O(n)
    Space: O(n), it could be better? Yeah, if we compute the algo online when reading the integer
    """
    n = len(array)
    effective_rot = rotations % n
    output = [0] * n

    for i in range(n):
        new_idx = i - effective_rot
        output[new_idx] = array[i]

    return output



if __name__ == "__main__":
    n, d = list(map(int, input().split()))
    arr = list(map(int, input().split()))

    rotated_arr = rot_left(d, arr)

    for x in rotated_arr:
        print(x, end=" ")
