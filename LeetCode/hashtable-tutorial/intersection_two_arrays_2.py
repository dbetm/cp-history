from collections import Counter
from typing import List


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        freq_nums1 = dict(Counter(nums1))
        freq_nums2 = dict(Counter(nums2))

        common_keys = set(freq_nums1.keys()).intersection(set(freq_nums2.keys()))

        output = list()

        for key in common_keys:
            output += [key] * min(freq_nums1[key], freq_nums2[key])

        return output



if __name__ == "__main__":
    sol = Solution()

    nums1 = list(map(int, input().split(" ")))
    nums2 = list(map(int, input().split(" ")))

    print(sol.intersect(nums1, nums2))