# https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
# Tag(s): Implementation, strings, sets

def sherlockAndAnagrams(s):
    all_sets = []
    ans = 0

    for i in range(len(s)):
        aux = ''
        aux_set = set()
        for j in range(i, len(s)):
            aux += s[j]
            aux_set.add("".join(sorted(aux)))

        all_sets.append(aux_set)

    n = len(all_sets)
    for i in range(n):
        for string in all_sets[i]:
            for j in range(i+1, n):
                if string in all_sets[j]:
                    ans += 1

    return ans


if __name__ == '__main__':
    q = int(input())

    for i in range(q):
        s = input()
        print(sherlockAndAnagrams(s))
