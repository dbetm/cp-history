# solved
# tags: strings, map, implementation


def generateDocument(characters, document):
    """My solution:
    Time: O(max(m, n))
    Space: O(max(m, n))

    where n is the number of chars in characters and m is the number of char in document
    """
    chars_map = dict()
    doc_map = dict()
    ans = True

    for c in characters:
        if c not in chars_map:
            chars_map[c] = 1
        else:
            chars_map[c] += 1

    for c in document:
        if c not in doc_map:
            doc_map[c] = 1
        else:
            doc_map[c] += 1

    for key_c in doc_map.keys():
        if doc_map[key_c] > chars_map.get(key_c, -1):
            ans = False
            break

    return ans


if __name__ == "__main__":
    characters = input("")
    document = input("")

    print(generateDocument(characters, document))

