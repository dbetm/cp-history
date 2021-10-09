# https://app.codesignal.com/interview-practice/task/4MoqQLaw22nrzXbgs/description
# Tag(s): Accumulated sum

def sumInRange(nums, queries):
    M = int(1e9 + 7)

    n = len(nums)
    sum = [nums[0]]
    total = 0

    for i in range(1, n):
        aux = (sum[i-1] % M + nums[i]) % M
        sum.append(aux)

    for q in queries:
        lower_bound = 0 if q[0] == 0 else sum[q[0]-1]
        total = (total + (sum[q[1]] - lower_bound)) % M

    return total % M


if __name__ == '__main__':
    nums = list(map(int, input().split()))
    queries = []
    num_queries = int(input())

    for _ in range(num_queries):
        i, j = list(map(int, input().split()))
        queries.append([i, j])

    print(sumInRange(nums, queries))
