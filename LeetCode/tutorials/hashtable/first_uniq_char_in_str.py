class Solution:
    def firstUniqChar(self, s: str) -> int:
        min_idx = 10e6
        found_unique = False

        hashmap = dict()

        for idx, c in enumerate(s):
            if c not in hashmap:
                hashmap[c] = [1, idx]
            else:
                hashmap[c][0] += 1

        for _, (count, idx) in hashmap.items():
            if count == 1 and min_idx > idx:
                min_idx = idx
                found_unique = True

        if not found_unique:
            return -1

        return min_idx