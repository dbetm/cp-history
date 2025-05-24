from typing import Dict, List


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        """My solution: accepted"""
        n34: Dict[int, set] = dict()
        n = len(nums)
        quadruplets = set()
        unique_pairs_34 = set()

        for idx in range(n):
            for jdx in range(idx + 1, n):
                if (nums[idx], nums[jdx]) in unique_pairs_34:
                    continue

                unique_pairs_34.add((nums[idx], nums[jdx]))

                sum_ = nums[idx] + nums[jdx]
                entry = n34.get(sum_, set())

                if (nums[idx], nums[jdx], idx, jdx) not in entry and (nums[jdx], nums[idx], jdx, idx) not in entry:
                    if len(entry) == 0:
                        n34[sum_] = {(nums[idx], nums[jdx], idx, jdx)}
                    else:
                        n34[sum_].add((nums[idx], nums[jdx], idx, jdx))

        # print(f"{n34=}")
        # print(len(n34))
        # print("-"*42)

        for idx in range(n):
            n1 = nums[idx]
            for jdx in range(idx+1, n):
                n2 = nums[jdx]

                x = target - (n1 + n2)

                if x in n34:
                    for (n3, n4, i3, i4) in n34[x]:
                        if i3 != idx and i3 != jdx and i4 != idx and i4 != jdx:
                            # print(
                            #     f"{n1=} at {idx}, "
                            #     f"{n2=} at {jdx}, "
                            #     f"{n3=} at {i3}, "
                            #     f"{n4=} at {i4}"
                            # )
                            quadruplets.add(tuple(sorted((n1, n2, n3, n4))))

        return [list(quadruplet) for quadruplet in quadruplets]


    def fourSum2(self, nums: List[int], target: int) -> List[List[int]]:
        """Proposal: Nice solutions, which is general for any K"""

        def kSum(nums: List[int], target: int, k: int) -> List[List[int]]:
            res = []

            # If we have run out of numbers to add, return res.
            if not nums:
                return res

            # There are k remaining values to add to the sum. The
            # average of these values is at least target // k.
            average_value = target // k

            # We cannot obtain a sum of target if the smallest value
            # in nums is greater than target // k or if the largest
            # value in nums is smaller than target // k.
            if average_value < nums[0] or nums[-1] < average_value:
                return res

            if k == 2:
                return twoSum(nums, target)

            for i in range(len(nums)):
                if i == 0 or nums[i - 1] != nums[i]:
                    for subset in kSum(nums[i + 1 :], target - nums[i], k - 1):
                        res.append([nums[i]] + subset)

            return res

        def twoSum(nums: List[int], target: int) -> List[List[int]]:
            res = []
            lo, hi = 0, len(nums) - 1

            while lo < hi:
                curr_sum = nums[lo] + nums[hi]
                if curr_sum < target or (lo > 0 and nums[lo] == nums[lo - 1]):
                    lo += 1
                elif curr_sum > target or (
                    hi < len(nums) - 1 and nums[hi] == nums[hi + 1]
                ):
                    hi -= 1
                else:
                    res.append([nums[lo], nums[hi]])
                    lo += 1
                    hi -= 1

            return res

        nums.sort()
        return kSum(nums, target, 4)


if __name__ == "__main__":
    sol = Solution()

    nums = list(map(int, input().split(" ")))
    target = int(input())

    print(sol.fourSum(nums, target))