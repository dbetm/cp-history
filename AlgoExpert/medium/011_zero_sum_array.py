# solved
# tags: implementation


def zeroSumSubarray(nums):
    """My solution:
    Time: O(n^2)
    Space: O(1)
    """
    n = len(nums)
    ans = False

    for idx in range(n):
        acc = 0
        for jdx in range(idx, n):
            acc += nums[jdx]

            if acc == 0:
                ans = True
                break

        if ans:
            break

    return ans


def zeroSumSubarray2(nums):
    """Proposal
    Time: O(n)
    Space: O(n)

    The idea is to exploit the fact that when a sum from 0 to idx is repeated, that means
    that a subarray is summing up to 0.
    """
    acc = 0
    all_sums_up_to_idx = set()

    for num in nums:
        acc += num

        if acc in all_sums_up_to_idx or num == 0 or acc == 0:
            return True

        all_sums_up_to_idx.add(acc)

    return False


if __name__ == "__main__":
    nums = list(map(int, input().split()))

    print(zeroSumSubarray(nums))
    print(zeroSumSubarray2(nums))