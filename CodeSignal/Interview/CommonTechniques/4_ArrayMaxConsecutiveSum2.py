# https://app.codesignal.com/interview-practice/task/dQD4TCunke2JQ98rj/description
# Tag(s): DP, Maths, Kadame algorithm

def arrayMaxConsecutiveSum2(arr):
    ans = -10002
    local_ans = 0

    for x in arr:
        local_ans += x

        if ans < local_ans:
            ans = local_ans

        if local_ans < 0:
            local_ans = 0

    return ans

if __name__ == '__main__':
    arr = list(map(int, input().split()))

    print(arrayMaxConsecutiveSum2(arr))
