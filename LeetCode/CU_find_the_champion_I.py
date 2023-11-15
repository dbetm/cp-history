from typing import List
# https://leetcode.com/problems/find-champion-i
# tags: arrays, implementation

class Solution:
    def findChampion(self, grid: List[List[int]]) -> int:
        n = len(grid)

        for idx, team in enumerate(grid):
            if sum(team) == (n-1):
                return idx


if __name__ == "__main__":
    sol = Solution()

    n = int(input(""))
    teams = list()

    for i in range(n):
        team = list(map(int, input("").split(" ")))
        teams.append(team)

    print(sol.findChampion(teams))