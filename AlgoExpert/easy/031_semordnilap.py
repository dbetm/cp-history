# solved
# tags: implementation, data-structures


def check_pair(word1, word2):
    if len(word1) != len(word2):
        return False

    left = 0
    right = len(word2) - 1

    while left < right:
        if word1[left] != word2[right]:
            return False

        left += 1
        right -= 1

    return True


def semordnilap(words):
    """My solution:
    Time: O(n^2)
    Space: O(max_num_pairs)

    Where n is the number of words.
    """
    pairs_set = set()
    ans = []

    n = len(words)

    for idx in range(n):
        base_word = words[idx]
        for jdx in range(idx+1, n):
            if (idx, jdx) not in pairs_set and check_pair(base_word, words[jdx]):
                pairs_set.add((idx, jdx))
                ans.append([base_word, words[jdx]])
                break

    return ans


def semordnilap2(words):
    """Proposal
    Time: O(n * m)
    Space: O(n * m)

    where n is the number of words and m is the lenght of the longest word
    """
    words_set = set(words)
    ans = list()

    for word in words:
        if word in words_set:
            reversed_word = word[::-1]
            if reversed_word in words_set and reversed_word != word:
                ans.append([word, reversed_word])
                words_set.remove(word)
                words_set.remove(reversed_word)

    return ans


if __name__ == "__main__":
    n = int(input())
    words = list()

    for i in range(n):
        word = input()
        words.append(word)
    
    print(semordnilap(words))