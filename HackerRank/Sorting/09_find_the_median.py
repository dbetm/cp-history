# https://www.hackerrank.com/challenges/find-the-median/problem
# tag(s): sorting, implementation


if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split(" ")))

    arr.sort()

    print(arr[len(arr) // 2])