# https://www.hackerrank.com/challenges/grid-challenge/problem
# tags: arrays, strings, sorting


def is_column_sorted(n: int, grid: list) -> bool:
    ans = True
    m = len(grid[0])

    for j in range(m):
        prev_char = "a"
        for i in range(n):
            #print(grid[i][j], end="")
            if grid[i][j] < prev_char:
                ans = False
                break
            
            prev_char = grid[i][j]
        #print("")

    return ans



if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        n = int(input())

        grid = list()

        for _ in range(n):
            row = list(input())
            row.sort()
            grid.append(row)

        ans = "YES" if is_column_sorted(n, grid) else "NO"
        print(ans)