from typing import List

# https://leetcode.com/problems/points-that-intersect-with-cars/submissions/
# tags: sets, implementation


class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        all_numbers = set()

        for coor in nums:
            for i in range(coor[0], coor[1] + 1):
                all_numbers.add(i)

        return len(all_numbers)



if __name__ == "__main__":
    sol = Solution()

    n = int(input(""))
    nums = list()

    for i in range(n):
        coordinates = list(map(int, input("").split(" ")))
        nums.append(coordinates)

    print(sol.numberOfPoints(nums))