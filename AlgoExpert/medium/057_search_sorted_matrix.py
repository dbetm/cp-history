# solved
# tags: sorting, implementation, binary-search

from bisect import bisect_left

# TODO: Check optimized version

def binary_search_col(matrix, col, left, right, target):
    if left >= right:
        return -1

    idx = (right - left) // 2 
    idx += left

    if matrix[idx][col] == target:
        return idx

    left_ans = binary_search_col(matrix, col, left, idx, target)

    if left_ans != -1:
        return left_ans

    return binary_search_col(matrix, col, idx+1, right, target)


def searchInSortedMatrix(matrix, target):
    """My solution
    Time: O(min(n, m) * log(max(n*m)))
    Space: O(log(max(n, m))) # assuming that bisec_left also uses recursion
    """
    current_row = 0
    current_col = 0

    n, m = len(matrix), len(matrix[0])

    limit = min(n, m)

    while current_col < limit:
        # look at the current column
        ans = binary_search_col(matrix, current_col, 0, n, target)

        if ans != -1:
            return (ans, current_col)

        # look at the current row
        ans = bisect_left(matrix[current_row], target)

        if ans < m and matrix[current_row][ans] == target:
            return (current_row, ans)
        
        current_col += 1
        current_row += 1

    # Write your code here.
    return (-1, -1)


if __name__ == "__main__":
    n, m = list(map(int, input().split()))
    target = int(input())
    matrix = list()

    for i in range(n):
        row = list(map(int, input().split()))
        matrix.append(row)

    print(searchInSortedMatrix(matrix, target))
