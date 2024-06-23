# solved
# tags: hash, map, strings, implementation


def minimumCharactersForWords(words):
    """ My solution:
    Time: O(n * max_lenght_word)
    Space: O(c)

    Where c is the number of unique chars across all the words.
    """

    chars = dict()
    ans = list()

    for word in words:
        map_for_word = dict()

        for c in word:
            if c in map_for_word:
                map_for_word[c] += 1
            else:
                map_for_word[c] = 1

        for c, count in map_for_word.items():
            if c in chars:
                if count > chars[c]:
                    chars[c] = count
            else:
                chars[c] = count

    for c, count in chars.items():
        for _ in range(count):
            ans.append(c)

    return ans


if __name__ == "__main__":
    words = input().split()

    print(minimumCharactersForWords(words))
