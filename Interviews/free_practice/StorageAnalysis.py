def max_of_min_storage(x, space):
    ans = 0
    i = 0
    for r in range(1, len(space) // x + 1):
        local_ans = 2e10
        for k in range(i, x * r):
            local_ans = min(local_ans, space[k])
            i += 1

        ans = max(ans, local_ans)

    if i < len(space):
        local_ans = 2e10
        for k in range(i, len(space)):
            local_ans = min(local_ans, space[k])

        ans = max(ans, local_ans)

    return ans

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    k = int(input())

    print(max_of_min_storage(k, arr))
