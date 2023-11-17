# https://leetcode.com/problems/count-largest-group
# tags: implementation, map, math

# podría computar todas las respuestas (y comprimir de alguna forma las mismas)
# y solo obtener la solución según el n dado.

class Solution:
    def countLargestGroup(self, n: int) -> int:
        max_number_groups = 0
        groups = dict() # key is the sum of digits
        ans = 0

        for num in range(1, n + 1):
            sum = self.computeDigitSum(num)

            if sum in groups:
                groups[sum] += 1
                max_number_groups = max(max_number_groups, groups[sum])
            else:
                groups[sum] = 1
                max_number_groups = max(max_number_groups, groups[sum])

        for val in groups.values():
            if val == max_number_groups:
                ans += 1

        return ans

    def computeDigitSum(self, n: int) -> int:
        sum = 0

        while(n > 0):
            sum += n % 10
            n = n // 10

        return sum


if __name__ == "__main__":
    sol = Solution()

    n = int(input(""))

    print(sol.countLargestGroup(n))