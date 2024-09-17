# solved
# tags: implementation, arrays


def zigzagTraverse(array):
    """My solution
    Time: O(n)
    Space: O(n)
    """
    n = len(array)
    m = len(array[0])

    if n == 0:
        return array[0]
    if m == 0:
        return [array[i][0] for i in range(n)]

    ans = list()
    LEFT = 0
    RIGHT = 1
    direction = LEFT

    num_elements = n * m
    i, j = 0, 0

    while len(ans) < num_elements:
        ans.append(array[i][j])

        # print(f"{ans}")
        # print(f"{i=}", f"{j=}")

        if direction == LEFT:
            if i+1 >= n:
                direction = RIGHT
                j += 1
            elif j-1 < 0:
                direction = RIGHT
                i += 1
            else:
                i += 1
                j -= 1
        else:
            if i-1 < 0 and j+1 < m:
                direction = LEFT
                j += 1
            elif j+1 >= m:
                direction = LEFT
                i += 1
            else:
                i -= 1
                j += 1

    return ans


if __name__ == "__main__":
    n, m = list(map(int, input().split()))

    array = list()

    for i in range(n):
        row = list(map(int, input().split(" ")))
        array.append(row)

    print(zigzagTraverse(array))
