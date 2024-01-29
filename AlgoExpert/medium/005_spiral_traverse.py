# solved
# tags: implementation, loops


def spiralTraverse(array):
    """My solution:
    Time: O(n)
    Space: O(n)
    """
    n = len(array)
    m = len(array[0])
    total = m * n
    row = 0
    col = 0
    ans = list()

    while len(ans) < total:
        print(f"row={row}, col={col}, n={n}, m={m}")

        # right
        for j in range(col, m - col):
            ans.append(array[row][j])

        # down
        for i in range(row + 1, n - row - 1):
            ans.append(array[i][m - col - 1])

        # left
        if (n - row - 1) > row:
            for j in range(m - col - 1, col - 1, -1):
                ans.append(array[n - row - 1][j])

        # up
        if col < (m - col - 1): 
            for i in range(n - row - 2, row, -1):
                ans.append(array[i][col])

        col += 1
        row += 1

    return ans


if __name__ == "__main__":
    n = int(input())
    array = list()

    for i in range(n):
        tmp = list(map(int, input().rstrip().split(" ")))
        array.append(tmp)
    
    print(spiralTraverse(array))
