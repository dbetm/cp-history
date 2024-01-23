import string as striing

# solved
# tags: strings, math


def caesarCipherEncryptor(string, key):
    """My solution:
    Time: O(n)
    Space: O(n)

    where n is the number of characters
    """
    alphabet = striing.ascii_lowercase
    string_encrypted = ""

    for c in string:
        idx = ord(c) - 97
        string_encrypted += alphabet[(idx + key) % 26]

    return string_encrypted


if __name__ == "__main__":
    k = int(input())
    string = input()

    print(caesarCipherEncryptor(string, k))
