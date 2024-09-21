#
# tags: 


import random
from collections import defaultdict
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
        matching_table = [defaultdict(lambda : set()) for _ in range(MAX_LENGHT_WORD)]
        n = len(words)

        for i in range(n):
            ref_word = words[i]

            for j in range(i+1, n):
                matches = count_matches(ref_word, words[j])
                matching_table[matches][i].add(j)
                matching_table[matches][j].add(i)

        from pprint import pprint
        pprint(matching_table)

        checked_words = set()

        for i in range(MAX_LENGHT_WORD - 1, -1, -1):
            for ref_idx, assoc_jdx in matching_table[i].items():
                if words[ref_idx] in checked_words:
                    continue
                
                matches = master.guess(words[ref_idx])

                print(f"{words[ref_idx]=}")

                if matches == MAX_LENGHT_WORD:
                    return

                if matches == 0 and i != 0:
                    continue

                checked_words.add(words[ref_idx])

                for jdx in assoc_jdx:
                    if words[ref_idx] in checked_words:
                        continue

                    matches = master.guess(words[jdx])

                    if matches == MAX_LENGHT_WORD:
                        return

                    checked_words.add(words[jdx])

        # for i in range(n):
        #     if words[i] in checked_words:
        #         continue
        #     matches = master.guess(words[i])
        #     checked_words.add(words[i])

        #     if matches == MAX_LENGHT_WORD:
        #         break

        #     # look at matches 
        #     for jdx_word_to_check in matching_table[matches][i]:
        #         if words[jdx_word_to_check] in checked_words:
        #             continue

        #         if master.guess(words[jdx_word_to_check]) == MAX_LENGHT_WORD:
        #             return

        #         checked_words.add(words[jdx_word_to_check])



if __name__ == "__main__":
    allowed_guesses = int(input(""))
    words = input("").split(" ")

    secret_word = random.choice(words)

    print(f"{secret_word=}")

    master = Master(secret_word, set(words), allowed_guesses)

    sol = Solution()

    sol.findSecretWord(words, master)

