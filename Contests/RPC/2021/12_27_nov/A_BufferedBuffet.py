# AC

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))

    arr.sort()
    ans = arr[0]

    for i in range(1, n):
        if arr[i] != arr[i-1]:
            ans += abs(arr[i-1] - arr[i])

        ans += arr[i]

    print(ans)
