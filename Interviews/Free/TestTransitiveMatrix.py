 def isTransitive(strArr):
    is_transitive = True
    ans = 'transitive'

    matrix = []
    row = []

    for row in strArr:
        for ch in row:
            if ch == ')':
                matrix.append(row.copy())
                row = []
            elif ch == '0' or ch == '1':
                row.append(ord(ch)-48)

    n = len(matrix)
    needed_transitions = '' # (x,y)-(x2-y2)-...
    for i in range(n):
        for j in range(i+1,n):
            pass


if __name__ == '__main__':
    strArr = ['(1,1,1)', '(0,1,1)', '(0,1,1)']

    print(isTransitive(strArr))
