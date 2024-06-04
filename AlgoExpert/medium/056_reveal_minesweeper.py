# solved
# tags: recursion, dfs, implementation


MINE_NOT_CLICKED = "M"
MINE_CLICKED = "X"
HIDDEN_CELD = "H"


def get_adjacent(board, x, y):
    num_mines = 0
    no_mines_coords = list()
    n = len(board)
    m = len(board[0])

    # up
    if (x-1) >= 0:
        if board[x-1][y] == MINE_NOT_CLICKED:
            num_mines += 1
        elif board[x-1][y] == HIDDEN_CELD:
            no_mines_coords.append((x-1, y))
    # down
    if (x+1) < n:
        if board[x+1][y] == MINE_NOT_CLICKED:
            num_mines += 1
        elif board[x+1][y] == HIDDEN_CELD:
            no_mines_coords.append((x+1, y))
    # left
    if (y-1) >= 0:
        if board[x][y-1] == MINE_NOT_CLICKED:
            num_mines += 1
        elif board[x][y-1] == HIDDEN_CELD:
            no_mines_coords.append((x, y-1))
    # right
    if (y+1) < m:
        if board[x][y+1] == MINE_NOT_CLICKED:
            num_mines += 1
        elif board[x][y+1] == HIDDEN_CELD:
            no_mines_coords.append((x, y+1))
    # up-left
    if (x-1) >= 0 and (y-1) >= 0:
        if board[x-1][y-1] == MINE_NOT_CLICKED:
            num_mines += 1
        elif board[x-1][y-1] == HIDDEN_CELD:
            no_mines_coords.append((x-1, y-1))
    # up-right
    if (x-1) >= 0 and (y+1) < m:
        if board[x-1][y+1] == MINE_NOT_CLICKED:
            num_mines += 1
        elif board[x-1][y+1] == HIDDEN_CELD:
            no_mines_coords.append((x-1, y+1))
    # down-left
    if (x+1) < n and (y-1) >= 0:
        if board[x+1][y-1] == MINE_NOT_CLICKED:
            num_mines += 1
        elif board[x+1][y-1] == HIDDEN_CELD:
            no_mines_coords.append((x+1, y-1))
    # down-right
    if (x+1) < n and (y+1) < m:
        if board[x+1][y+1] == MINE_NOT_CLICKED:
            num_mines += 1
        elif board[x+1][y+1] == HIDDEN_CELD:
            no_mines_coords.append((x+1, y+1))

    return num_mines, no_mines_coords


def revealMinesweeper(board, row, column):
    """My solution
    Time: O(n*m)
    Space: O(n*m)
    """
    if board[row][column] == MINE_NOT_CLICKED:
        board[row][column] = MINE_CLICKED
    elif board[row][column] == HIDDEN_CELD:
        num_mines, coords = get_adjacent(board, row, column)

        if num_mines > 0:
            board[row][column] = str(num_mines)
        else:
            board[row][column] = "0"
            # for (x, y) in coords:
            #     board[x][y] = "0"
            for (x, y) in coords:
                revealMinesweeper(board, x, y)

    return board



def print_board(board):
    for row in board:
        print(row)


if __name__ == "__main__":
    n, m = list(map(int, input().split()))
    row, column = list(map(int, input().split()))
    board = list()

    for i in range(n):
        tmp = list(input("").split(" "))
        board.append(tmp)

    from pprint import pprint

    print_board(board)
    print("----")
    print_board(revealMinesweeper(board, row, column))