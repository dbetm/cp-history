# 
# tags:

from pprint import pprint

has_edges = False
pos_to_keep = list()


def explore(matrix, i, j):
    global has_edges

    if has_edges:
        return

    n = len(matrix)
    m = len(matrix[0])

    if i >= n or j >= m:
        return
    if matrix[i][j] == 0:
        return

    matrix[i][j] = 0
    pos_to_keep.append((i, j))

    def is_edge(x, dim):
        return x == (dim-1) or x == 0

    has_edges = is_edge(i, n) or is_edge(j, m)

    # up
    explore(matrix, i-1, j)
    # down
    explore(matrix, i+1, j)
    # left
    explore(matrix, i, j-1)
    # right
    explore(matrix, i, j+1)



def removeIslands(matrix):
    """My solution
    Time: O(n*m)
    Space: O(n*m)
    """
    n = len(matrix)
    m = len(matrix[0])

    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 1:
                global has_edges
                global pos_to_keep

                has_edges = False
                pos_to_keep = list()

                explore(matrix, i, j)

                if has_edges:
                    for (x, y) in pos_to_keep:
                        matrix[x][y] = 1

    return matrix



if __name__ == "__main__":
    n, m = list(map(int, input().split()))
    matrix = list()

    for i in range(n):
        row = list(map(int, input().split()))
        matrix.append(row)

    pprint(removeIslands(matrix))