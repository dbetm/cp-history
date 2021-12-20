# https://www.hackerrank.com/challenges/insertionsort2/problem
# Tag(s): sorting

def _print(arr):
    for x in arr:
        print(x, end=' ')
    print()


def insertionSort1(n, arr):
    k = arr[n-1]
    index = n - 2

    while index >= 0:
        if arr[index] < k:
            if index + 1 < n:
                arr[index + 1] = k
            index = 0
        else:
            arr[index + 1] = arr[index]
            if index == 0:
                arr[0] = k

        index -= 1


def insertionSort2(n, arr):

    for i in range(2, n+1):
        insertionSort1(i, arr)
        _print(arr)


if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))

    insertionSort2(n, arr)
