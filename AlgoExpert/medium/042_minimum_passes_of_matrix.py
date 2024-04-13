#
# tags:

from pprint import pprint
import copy


def minimumPassesOfMatrix(matrix: list):
    """My solution
    Time: O((n*m)^2)
    Space: O(n*m)
    """
    n = len(matrix)
    m = len(matrix[0])
    num_passes = 0

    def can_change(x, y):
        ans = False
        # left
        if (y-1) >= 0 and matrix[x][y-1] > 0:
            ans = True
        # right
        if (y+1) < m and matrix[x][y+1] > 0:
            ans = True
        # up
        if (x-1) >= 0 and matrix[x-1][y] > 0:
            ans = True
        # down
        if (x+1) < n and matrix[x+1][y] > 0:
            ans = True

        return ans

    while True:
        num_negatives = 0
        num_changes = 0
        tmp = copy.deepcopy(matrix)

        for i in range(n):
            for j in range(m):
                if matrix[i][j] < 0:
                    num_negatives += 1

                    if can_change(i, j):
                        num_changes += 1
                        tmp[i][j] = abs(matrix[i][j])

        if num_negatives > 0 and num_changes == 0:
            return -1

        if num_negatives == 0:
            break

        num_passes += 1
        matrix = tmp

    return num_passes



def minimumPassesOfMatrix2(matrix: list):
    """Proposal
    Time: O(n*m)
    Space: O(n*m)
    """
    n = len(matrix)
    m = len(matrix[0])

    def bfs(all_positives: tuple) -> int:
        num_passes = 0
        queue = list()

        for (element, x, y) in all_positives:
            queue.append((element, x, y))

        queue.append((None, None, None))

        while len(queue) > 0:
            element, x, y = queue.pop(0)
            print(f"{element = }")

            if element == None:
                if len(queue) > 0:
                    queue.append((None, None, None))
                    num_passes += 1 
            else:
                if (x-1) >= 0 and matrix[x-1][y] < 0:
                    #num_conversions += 1
                    print("adding", matrix[x-1][y])
                    matrix[x-1][y] = abs(matrix[x-1][y])
                    queue.append((matrix[x-1][y], x-1, y))
                if (x+1) < n and matrix[x+1][y] < 0:
                    #num_conversions += 1
                    print("adding", matrix[x+1][y])
                    matrix[x+1][y] = abs(matrix[x+1][y])
                    queue.append((matrix[x+1][y], x+1, y))
                if (y-1) >= 0 and matrix[x][y-1] < 0:
                    #num_conversions += 1
                    print("adding", matrix[x][y-1])
                    matrix[x][y-1] = abs(matrix[x][y-1])
                    queue.append((matrix[x][y-1], x, y-1))
                if (y+1) < m and matrix[x][y+1] < 0:
                    #num_conversions += 1
                    print("adding", matrix[x][y+1])
                    matrix[x][y+1] = abs(matrix[x][y+1])
                    queue.append((matrix[x][y+1], x, y+1))

        return num_passes

    all_positives = list()

    for i in range(n):
        for j in range(m):
            if matrix[i][j] > 0:
                all_positives.append((matrix[i][j], i, j))

    ans = bfs(all_positives)

    # check if there are still negatives
    for i in range(n):
        for j in range(m):
            if matrix[i][j] < 0:
                return -1

    return ans


if __name__ == "__main__":
    n, m = list(map(int, input().split()))
    matrix = list()

    for i in range(n):
        tmp = list(map(int, input().split()))
        matrix.append(tmp)

    print(minimumPassesOfMatrix2(matrix))
