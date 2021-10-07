# https://app.codesignal.com/interview-practice/task/5A8jwLGcEpTPyyjTB/description
# Tag(s): Arrays

def rotateImage(a):
    n = len(a)

    for i in range(n):
        for j in range(i+1, n):
            a[i][j], a[j][i] = a[j][i], a[i][j]

    for i in range(n):
        a[i].reverse()

    return a


if __name__ == '__main__':
    n = int(input())

    arr = []

    for i in range(n):
        aux = list(map(int, input().split()))
        arr.append(aux)

    print(rotateImage(arr))
