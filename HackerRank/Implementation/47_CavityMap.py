# https://www.hackerrank.com/challenges/cavity-map/problem
# Tag(s): Implementation

def find_cavities(grid:list) -> list:
    n = len(grid)

    for i in range(1, n-1):
        for j in range(1, n-1):
            if grid[i][j] > grid[i-1][j] and grid[i][j] > grid[i+1][j]:
                if grid[i][j] > grid[i][j-1] and grid[i][j] > grid[i][j+1]:
                    grid[i][j] = 'X'

    return grid


if __name__ == '__main__':
    n = int(input())
    grid = []

    for i in range(n):
        digs = list(input())
        grid.append(digs)

    modified_grid = find_cavities(grid)

    for row in modified_grid:
        for x in row:
            print(x, end='')
        print("")
