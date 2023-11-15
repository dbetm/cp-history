# https://leetcode.com/problems/minimize-string-length
# tags: implementation

class Solution:
    def minimizedStringLength(self, s: str) -> int:
        return len(set(s))



if __name__ == "__main__":
    sol = Solution()

    s = input("")

    print(sol.minimizedStringLength(s))