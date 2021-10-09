# https://app.codesignal.com/interview-practice/task/3PcnSKuRkqzp8F6BN/description
# Tag(s): strings, implementation
""" Alternative solution:
strings like a set must have the same cardinality X of patterns like a set, in
addition the pairs string-pattern like a set must have the same cardinality X.
"""

def areFollowingPatterns(strings, patterns):
    map = dict()
    used_words = set()
    ans = True

    for p, word in zip(patterns, strings):
        if not p in map:
            if word in used_words:
                ans = False
                break
            map[p] = word
            used_words.add(word)
        else:
            if map[p] != word:
                ans = False
                break

    return ans


if __name__ == '__main__':
    strings = list(input().split())
    patterns = list(input().split())

    print(areFollowingPatterns(strings, patterns))
