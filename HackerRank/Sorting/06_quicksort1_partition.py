# https://www.hackerrank.com/challenges/quicksort1/problem
# tag(s): sorting, implementation


def partition(arr: list, idx_pivot: int = 0) -> list:
    pivot = arr[idx_pivot]

    left = list()
    equal = list()
    right = list()

    for x in arr:
        if x > pivot:
            right.append(x)
        elif x == pivot:
            equal.append(x)
        else:
            left.append(x)

    return [*left, *equal, *right]



if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split(" ")))

    res = partition(arr)

    for x in res:
        print(x, end=" ")

