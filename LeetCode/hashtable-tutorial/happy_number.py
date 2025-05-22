class Solution:
    def __get_squared_sum(self, n: int) -> int:
        squared_sum = 0

        while n > 0:
            squared_sum += (n % 10)**2
            n = n // 10

        return squared_sum

    def isHappy(self, n: int) -> bool:
        checked_values = set()

        while True:
            checked_values.add(n)
            n = self.__get_squared_sum(n)

            if n == 1:
                return True
            if n in checked_values:
                return False