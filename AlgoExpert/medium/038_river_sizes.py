# solved
# tags: recursion, dfs, graph

cont = 0

def dfs(matrix, i, j):
    n = len(matrix)
    m = len(matrix[0])

    if i < 0 or i >= n or j < 0 or j >= m:
        return
    if matrix[i][j] == 0:
        return

    global cont
    cont += 1
    matrix[i][j] = 0

    # up
    dfs(matrix, i-1, j)
    # down
    dfs(matrix, i+1, j)
    # left
    dfs(matrix, i, j-1)
    # right
    dfs(matrix, i, j+1)


def riverSizes(matrix):
    """ My solution
    Time: O(n*m)
    Space: O(n*m) (because stack of recursion)
    """
    n = len(matrix)
    m = len(matrix[0])
    sizes = list()

    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 1:
                global cont
                cont = 0
                dfs(matrix, i, j)
                sizes.append(cont)

    return sizes


if __name__ == "__main__":
    n, m = list(map(int, input().split()))
    matrix = list()

    for i in range(n):
        row = list(map(int, input().split()))
        matrix.append(row)

    print(riverSizes(matrix))
