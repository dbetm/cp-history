# solved
# tags: hash, map, strings


def groupAnagrams(words):
    """My solution:
    Time: O(n * x * ln(x))
    Space: O(n*x)

    Where x is the max lenght of words
    """
    groups = dict()

    for word in words:
        hash = "".join(sorted(word))

        if hash in groups:
            groups[hash].append(word)
        else:
            groups[hash] = [word]

    return list(groups.values())



if __name__ == "__main__":
    words = input("").split(" ")

    print(groupAnagrams(words))
