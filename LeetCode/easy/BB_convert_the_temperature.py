# https://leetcode.com/problems/convert-the-temperature
# tags: implementation

class Solution:
    def convertTemperature(self, celsius: float) -> List[float]:
        return [celsius + 273.15, celsius * 1.80 + 32.00]



if __name__ == "__main__":
    sol = Solution()

    celsius = float(input(""))

    print(sol.convertTemperature((celsius)))