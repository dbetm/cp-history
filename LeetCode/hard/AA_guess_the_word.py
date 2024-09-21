# https://leetcode.com/problems/guess-the-word
# tags: divide-and-conquer, implementation, strings

import random
from typing import List



def count_matches(word_a: str, word_b: str) -> int:
    matches = 0
    for a, b in zip(word_a, word_b):
        matches += 1 if a == b else 0

    return matches


MAX_LENGHT_WORD = 6


class Master:
    def __init__(self, secret_word: str, words: set, allowed_guesses: int):
        self.secret_word = secret_word
        self.words = words
        self.attempts = allowed_guesses

    def guess(self, word: str) -> int:
        if self.attempts < 0:
            print("Either you took too many guesses, or you did not find the secret word.")

        self.attempts -= 1

        if word not in self.words:
            return -1

        matches = count_matches(word, self.secret_word)

        if matches == MAX_LENGHT_WORD:
            print("You guessed the secret word correctly.")

        return matches


class Solution:
    def findSecretWord(self, words: List[str], master: Master) -> None:
        """Proposal
        Time: O(n^2)
        Space: O(n)
        """

        # 1) Iterate until found the secret word or check all the words (n guesses)
        # 2) At each iteration, reduce the number of set of words to check
        # 3) To reduce the wordlist, only consider the words that have the same match of chars
        # that the choosen word had with the secret word

        n = len(words)

        for _ in range(n):
            candidate = random.choice(words)

            matches = master.guess(candidate)

            if matches == MAX_LENGHT_WORD:
                break

            candidates = list()

            for word in words:
                if count_matches(candidate, word) == matches:
                    candidates.append(word)

            words = candidates



if __name__ == "__main__":
    allowed_guesses = int(input(""))
    words = input("").split(" ")

    secret_word = random.choice(words)

    print(f"{secret_word=}")

    master = Master(secret_word, set(words), allowed_guesses)

    sol = Solution()

    sol.findSecretWord(words, master)

