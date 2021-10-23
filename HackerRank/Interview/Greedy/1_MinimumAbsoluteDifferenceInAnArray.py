# https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/problem
# Tag(s): Greedy 

def minimumAbsoluteDifference(arr):
    arr.sort()
    ans = abs(arr[0] - arr[1])

    n = len(arr)

    for i in range(2, n):
        ans = min(ans, abs(arr[i-1] - arr[i]))

    return ans

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))

    print(minimumAbsoluteDifference(arr))
