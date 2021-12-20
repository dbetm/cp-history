# https://www.hackerrank.com/challenges/insertionsort1/problem
# Tag(s): sorting

def _print(arr):
    for x in arr:
        print(x, end=' ')
    print()

def insertionSort1(n, arr):
    k = arr[-1]
    index = n - 2

    while index >= 0:
        if arr[index] < k:
            if index + 1 < n:
                arr[index + 1] = k
            index = 0
        else:
            arr[index + 1] = arr[index]
            if index == 0:
                _print(arr)
                arr[0] = k

        _print(arr)
        index -= 1

    if n == 1:
        _print(arr)


if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))

    insertionSort1(n, arr)
