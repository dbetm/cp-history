class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        unique_jewels = set(jewels)

        answer = 0

        for stone in stones:
            if stone in unique_jewels:
                answer += 1

        return answer