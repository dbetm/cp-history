# https://app.codesignal.com/interview-practice/task/SKZ45AF99NpbnvgTn/description
# Tag(s): Arrays, implementation

def getIndexSubgrid(i, j):
    index = -1

    if i < 3 and j < 3:
        index = 0
    elif i < 3 and j < 6:
        index = 1
    elif i < 3 and j < 9:
        index = 2
    elif i < 6 and j < 3:
        index = 3
    elif i < 6 and j < 6:
        index = 4
    elif i < 6 and j < 9:
        index = 5
    elif i < 9 and j < 3:
        index = 6
    elif i < 9 and j < 6:
        index = 7
    else:
        index = 8

    return index

def sudoku2(grid):
    n = 9
    ans = True

    columns = [set() for i in range(n)]
    rows = [set() for i in range(n)]
    subgrids = [set() for i in range(n)]

    # explore
    for i in range(n):
        for j in range(n):
            if grid[i][j] == '.':
                continue
            # column
            if grid[i][j] in columns[j]:
                ans = False
                break
            else:
                columns[j].add(grid[i][j])
            # rows
            if grid[i][j] in rows[i]:
                ans = False
                break
            else:
                rows[i].add(grid[i][j])
            # subgrids
            index = getIndexSubgrid(i, j)
            if grid[i][j] in subgrids[index]:
                ans = False
                break
            else:
                subgrids[index].add(grid[i][j])

        if ans == False:
            break

    return ans


if __name__ == '__main__':
    grid = []

    for i in range(9):
        row = list(input().split())
        grid.append(row)

    print(sudoku2(grid))
