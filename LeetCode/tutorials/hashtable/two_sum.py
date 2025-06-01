from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {num: idx for idx, num in enumerate(nums)}

        for idx, num in enumerate(nums):
            candidate = target - num

            if candidate in hashmap:
                if hashmap[candidate] != idx:
                    return [idx, hashmap[candidate]]