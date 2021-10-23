import copy
# https://app.codesignal.com/interview-practice/task/v3uf4PGocp2CH62nn/description
# Tag(s): Backtracking, recursion
def print_board(board):
    for row in board:
        print(row)

deltas = [
    (-1, 0), (-1, -1), (-1, 1), (0, -1),
    (0, 1), (1, 0), (1, -1), (1, 1)
]

def explore(board, word, i, j, k):
    if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]):
        return False

    if board[i][j] == '-' or k >= len(word):
        return False

    if board[i][j] != word[k]:
        return False

    original_chr = board[i][j]
    board[i][j] = '-'

    if k == (len(word)-1):
        return True

    ans = False

    for delta in deltas:
        if explore(board, word, i+delta[0], j+delta[1], k+1):
            ans = True
            break

    board[i][j] = original_chr # backtracking

    return ans


def wordBoggle(board, words):
    ans = []

    for word in words:
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] == word[0]:
                    tmp_board = copy.deepcopy(board)
                    if explore(tmp_board, word, i, j, 0):
                        ans.append(word)
                        break
            else:
                continue
            break

    ans.sort()
    return ans

if __name__ == '__main__':
    board = []
    rows = int(input())

    for _ in range(rows):
        x = input().split()
        board.append(x)

    words = input().split()

    print(wordBoggle(board, words))
