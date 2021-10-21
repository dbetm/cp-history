def compute(nums, n, dp):
    if n <= 0:
        return 0

    if dp[n] != -1:
        return dp[n]

    dp[n] = max(nums[n-1] + compute(nums, n-2, dp), compute(nums, n-1, dp))

    return dp[n]


def houseRobber(nums):
    n = len(nums)
    dp = [-1] * (n+1)
    return compute(nums, n, dp)

# Alternative solution
"""
def houseRobber(nums):
    a, b = 0, 0
    for i in nums:
        a, b = max(b+i, a), a
    return max(a, b)
"""

if __name__ == '__main__':
    nums = list(map(int, input().split()))

    print(houseRobber(nums))
