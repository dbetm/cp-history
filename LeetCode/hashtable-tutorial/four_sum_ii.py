from typing import List


class Solution:
    def fourSumCount(
        self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]
    ) -> int:
        
        hm34 = dict()
        count = 0

        for num3 in nums3:
            for num4 in nums4:
                key = num3 + num4
                hm34[key] = hm34.get(key, 0) + 1

        #print(f"{hm4=}")

        for n1 in nums1:
            for n2 in nums2:
                sum = n1 + n2

                target = -(sum)

                if target in hm34:
                    #print(f"{sum=} + {target=}    |||", f"{n1}+{n2}+{n3}")
                    count += hm34[target]

        return count


if __name__ == "__main__":
    sol = Solution()

    nums1 = list(map(int, input().split(" ")))
    nums2 = list(map(int, input().split(" ")))
    nums3 = list(map(int, input().split(" ")))
    nums4 = list(map(int, input().split(" ")))

    print(sol.fourSumCount(nums1, nums2, nums3, nums4))