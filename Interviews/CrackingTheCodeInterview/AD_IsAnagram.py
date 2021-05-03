
def is_anagram(str_1, str_2):

    return sorted(str_1) == sorted(str_2)


if __name__ == '__main__':
    str_1 = input("Type first word: ")
    str_2 = input("Type second word: ")

    print(is_anagram(str_1, str_2))
