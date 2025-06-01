from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = nums[0]
        n = len(nums)

        for idx in range(1, n):
            num = nums[idx]
            ans ^= num

        return ans
    



if __name__ == "__main__":
    x = list(map(int, input("").split(" ")))

    sol = Solution()

    print(sol.singleNumber(x))