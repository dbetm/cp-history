# https://www.hackerrank.com/challenges/ctci-ransom-note
# tags: hashmaps, strings, implementation

from collections import Counter


def check_if_can_build_note(magazine: list, note: list) -> bool:
    available_word_list = Counter(magazine)
    is_possible = True

    for word in note:
        if available_word_list[word] == 0:
            is_possible = False
            break

        available_word_list[word] -= 1

    return is_possible


if __name__ == "__main__":
    m, n = list(map(int, input().split()))

    magazine = input().split(" ")
    note = input().split(" ")

    print("Yes" if check_if_can_build_note(magazine, note) else "No")
