from collections import defaultdict
from typing import List
# https://leetcode.com/problems/minimum-domino-rotations-for-equal-row
# tag(s): hashmaps, arrays, implementation


class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        """My solution
        Time: O(n)
        Space: O(1) , since this a maximum number of elements to store, in this case (6*2*2 = 24)
        """
        tops_freqs = defaultdict(lambda: 0)
        bottoms_freqs = defaultdict(lambda: 0)
        n = len(tops)
        min_num_rotations = -1

        max_freq_top = -1
        popular_top = -1
        max_freq_bottom = -1
        popular_bottom = -1

        for i in range(n):
            tops_freqs[tops[i]] += 1
            bottoms_freqs[bottoms[i]] += 1

            if tops_freqs[tops[i]] > max_freq_top:
                max_freq_top = tops_freqs[tops[i]]
                popular_top = tops[i]

            if bottoms_freqs[bottoms[i]] > max_freq_bottom:
                max_freq_bottom = bottoms_freqs[bottoms[i]]
                popular_bottom = bottoms[i]

        if max_freq_top >= max_freq_bottom and (max_freq_bottom + bottoms_freqs[popular_top]) >= n:
            num_rotations = 0
            is_possible = True

            for i in range(n):
                if tops[i] == popular_top:
                    continue

                if bottoms[i] != popular_top:
                    is_possible = False
                    break

                num_rotations += 1
            
            if is_possible:
                min_num_rotations = num_rotations

        if max_freq_bottom >= max_freq_top and (max_freq_bottom + tops_freqs[popular_bottom]) >= n:
            num_rotations = 0
            is_possible = True

            for i in range(n):
                if bottoms[i] == popular_bottom:
                    continue

                if tops[i] != popular_bottom:
                    is_possible = False
                    break

                num_rotations += 1

            if is_possible:
                if min_num_rotations == -1:
                    min_num_rotations = num_rotations
                else:
                    min_num_rotations = min(min_num_rotations, num_rotations)

        return min_num_rotations



if __name__ == "__main__":
    tops = list(map(int, input().split(" ")))
    bottoms = list(map(int, input().split(" ")))

    sol = Solution()

    print(sol.minDominoRotations(tops, bottoms))