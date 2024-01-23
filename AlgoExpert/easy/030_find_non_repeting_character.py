# solved
# tags: implementation, map, strings


def firstNonRepeatingCharacter(string):
    """My solution:
    Time: O(n)
    Space: O(1)

    where n is the number of characters. The constant space is because the input string
    only has lowercase English-alphabet letters; thus, our hash table will never have more
    than 26 characters frequencies.
    """
    mapping = dict()

    for idx, c in enumerate(string):
        if c not in mapping:
            mapping[c] = [1, idx]
        else:
            mapping[c][0] += 1

    idx = -1

    for _, (count, jdx) in mapping.items():
        if count == 1:
            if idx == -1 or jdx < idx:
                idx = jdx

    return idx


if __name__ == "__main__":
    string = input()

    print(firstNonRepeatingCharacter(string))

