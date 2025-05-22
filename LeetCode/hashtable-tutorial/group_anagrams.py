from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashmap = dict()

        for str_ in strs:
            sorted_str_ = "".join(sorted(str_))

            if sorted_str_ in hashmap:
                hashmap[sorted_str_].append(str_)
            else:
                hashmap[sorted_str_] = [str_]

        return [value for value in hashmap.values()]
    


if __name__ == "__main__":
    sol = Solution()

    strs = input().split(" ")

    print(sol.groupAnagrams(strs))