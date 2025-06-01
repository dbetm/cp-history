
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        hashmap = dict()
        res = ""

        if len(s) != len(t):
            return False

        for idx, c in enumerate(s):
            if c in hashmap:
                res += hashmap[c]
            else:
                hashmap[c] = t[idx]
                res += t[idx]

        if res != t:
            return False

        # now check if we can get s from t using the inverse hashmap
        res2 = ""
        inv_hashmap = {value: key for key, value in hashmap.items()}

        for c in t:
            res2 += inv_hashmap[c]

        #print(f"{res=}", f"{t=}")
        return res2 == s
    


if __name__ == "__main__":
    sol = Solution()

    s = input()
    t = input()

    print(sol.isIsomorphic(s, t))