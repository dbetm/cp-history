class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest_substr = 0

        substr = set()
        cont = 0

        for idx, c in enumerate(s):
            cont += 1

            if c not in substr:
                substr.add(c)
            else:
                cont -= 1
                if cont > longest_substr:
                    longest_substr = cont

                jdx = idx - 1
                substr = {c}
                cont = 1

                while s[jdx] != c:
                    substr.add(s[jdx])
                    jdx -= 1
                    cont += 1

        if cont > longest_substr:
            longest_substr = cont

        return longest_substr

    def lengthOfLongestSubstring2(self, s: str) -> int:
        chart_set = set()
        left = 0
        max_lenght = 0
        
        for right in range(len(s)):
            if s[right] not in chart_set:
                chart_set.add(s[right])

                if len(chart_set) > max_lenght:
                    max_lenght = len(chart_set)
            else:
                while s[right] in chart_set:
                    chart_set.remove(s[left])
                    left += 1
                chart_set.add(s[right])

        return max_lenght


if __name__ == "__main__":
    s = input("")

    sol = Solution()

    print(sol.lengthOfLongestSubstring(s))