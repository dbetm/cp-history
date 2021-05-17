
def to_zero(matrix):
    m = len(matrix)
    n = len(matrix[0])
    is_zeros_pivots = False

    for i in range(1, m):
        for j in range(1, n):
            if matrix[i][j] == 0:
                matrix[0][j] = 0
                matrix[i][0] = 0
                is_zeros_pivots = True

    if is_zeros_pivots:
        for i in range(1, n):
            if matrix[0][i] == 0:
                for x in range(1, m):
                    matrix[x][i] = 0

        for i in range(1, m):
            if matrix[i][0] == 0:
                for x in range(1, n):
                    matrix[i][x] = 0

    for i in range(m):
        matrix[i][0] = 0

    for i in range(n):
        matrix[0][i] = 0

    return matrix


if __name__ == '__main__':
    matrix = []
    m = int(input("Type m: "))
    # n = input("Type n: ")

    for i in range(m):
        row = list(map(int, input().split()))
        matrix.append(row)


    print(to_zero(matrix))
