#  https://leetcode.com/problems/expressive-words
# tags: strings, hashmaps, implementation

from typing import List



def get_compressed_word_repr(word: str) -> list:
    compressed_word = list()

    idx = 0
    n = len(word)

    while idx < n:
        compressed_word.append([word[idx], 1])
        idx += 1

        while idx < n and word[idx] == word[idx-1]:
            compressed_word[-1][1] += 1
            idx += 1

    return compressed_word



class Solution:
    def expressiveWords(self, s: str, words: List[str]) -> int:
        """My solution
        Time: O(num_words * max_lenght_word)
        Space: O(max(len(s), max_lenght_word))
        """

        s_compressed = get_compressed_word_repr(s)
        num_strechy_words = 0

        print(f"{s_compressed=}")

        for word in words:
            word_compressed = get_compressed_word_repr(word)

            print(f"{word_compressed=}")

            if self.is_strechy(s_compressed, word_compressed):
                num_strechy_words += 1

        return num_strechy_words


    def is_strechy(self, s_compresed: str, word_compressed: str) -> bool:
        if len(s_compresed) != len(word_compressed):
            return False

        ans = True

        for (s_ch, s_freq), (w_ch, w_freq) in zip(s_compresed, word_compressed):
            if s_ch != w_ch or s_freq < w_freq or (s_freq < 3 and s_freq != w_freq):
                ans = False
                break

        return ans



if __name__ == "__main__":
    s = input("")
    n = int(input(""))

    words = list()

    for i in range(n):
        word = input("")

        words.append(word)

    sol = Solution()

    print(sol.expressiveWords(s, words))
