def isTransitive(strArr):
    is_transitive = True
    matrix = []
    row = []

    for tuple in strArr:
        for ch in tuple:
            if ch == ')':
                matrix.append(row.copy())
                row = []
            elif ch == '0' or ch == '1':
                row.append(ord(ch)-48)

    n = len(matrix)
    needed_transitions = '' # (x,y)-(x2-y2)-...
    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                if matrix[i][j] == 1 and matrix[j][k] == 1:
                    if matrix[i][k] != 1:
                        is_transitive = False
                        needed_transitions += '({},{})-'.format(i, k)

    if is_transitive == False:
        needed_transitions = needed_transitions[:len(needed_transitions)-1]
        return needed_transitions

    return 'transitive'

if __name__ == '__main__':
    strArr = ['(1,1,1)', '(0,1,1)', '(0,1,1)']
    # strArr = ['(1,1,0)', '(0,1,1)', '(0,1,1)']

    print(isTransitive(strArr))
