# solved
# tags: strings, hash, implementation


def commonCharacters(strings):
    """My solution:
    Time: O(m)
    Space: O(m)

    where m is the number of characters considering all the strings
    """
    mapping = dict()
    n = len(strings)

    for idx, string in enumerate(strings):
        for c in string:
            if c not in mapping:
                mapping[c] = {idx}
            else:
                mapping[c].add(idx)

    ans = list()
    for c, idxes in mapping.items():
        if len(idxes) == n:
            ans.append(c)

    return ans


if __name__ == "__main__":
    n = int(input())

    arr = list()

    for i in range(n):
        string = input()
        arr.append(string)

    print(commonCharacters(arr))

