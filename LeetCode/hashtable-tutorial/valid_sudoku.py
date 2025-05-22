from typing import List
from collections import defaultdict


class Solution:
    def __solve_min_square_key(self, i: int, j: int) -> str:
        return f"{i//3}i-{j//3}j"

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        columns_map = defaultdict(set)
        rows_map = defaultdict(set)
        squares_map = defaultdict(set)
        n = len(board)
        m = len(board[0])

        for i in range(n):
            for j in range(m):
                if board[i][j] == ".":
                    continue

                # check row
                if board[i][j] in rows_map[i]:
                    return False
                else:
                    rows_map[i].add(board[i][j])

                # check column
                if board[i][j] in columns_map[j]:
                    return False
                else:
                    columns_map[j].add(board[i][j])

                # check mini 3x3 square
                key = self.__solve_min_square_key(i, j)
                if board[i][j] in squares_map[key]:
                    return False
                else:
                    squares_map[key].add(board[i][j])

        return True


if __name__ == "__main__":
    board1 = [
        ["5","3",".",".","7",".",".",".","."]
        ,["6",".",".","1","9","5",".",".","."]
        ,[".","9","8",".",".",".",".","6","."]
        ,["8",".",".",".","6",".",".",".","3"]
        ,["4",".",".","8",".","3",".",".","1"]
        ,["7",".",".",".","2",".",".",".","6"]
        ,[".","6",".",".",".",".","2","8","."]
        ,[".",".",".","4","1","9",".",".","5"]
        ,[".",".",".",".","8",".",".","7","9"]
    ]

    board = [
        ["8","3",".",".","7",".",".",".","."]
        ,["6",".",".","1","9","5",".",".","."]
        ,[".","9","8",".",".",".",".","6","."]
        ,["8",".",".",".","6",".",".",".","3"]
        ,["4",".",".","8",".","3",".",".","1"]
        ,["7",".",".",".","2",".",".",".","6"]
        ,[".","6",".",".",".",".","2","8","."]
        ,[".",".",".","4","1","9",".",".","5"]
        ,[".",".",".",".","8",".",".","7","9"]
    ]

    sol = Solution()

    print(sol.isValidSudoku(board))