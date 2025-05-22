from typing import List


class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        hashmap = dict()

        for idx, num in enumerate(nums):
            if num in hashmap and hashmap[num] != idx:
                if abs(hashmap[num] - idx) <= k:
                    return True
                else:
                    hashmap[num] = idx
            else:
                hashmap[num] = idx

        return False