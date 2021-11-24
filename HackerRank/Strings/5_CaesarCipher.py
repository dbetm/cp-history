# https://www.hackerrank.com/challenges/caesar-cipher-1/problem
# Tag(s): Strings, maths, implementation

def cipher_caesar_string(s : str, k : int) -> str:
    alphabet = 'abcdefghijklmnopqrstuvwxyz'

    ans = ''

    for c in s:
        aux = c
        if c.isalpha():
            aux = c.lower()
            index = ord(aux) - 97
            aux = alphabet[(index + k) % 26]

            if c.isupper():
                aux = aux.upper()

        ans += aux

    return ans


if __name__ == '__main__':
    n = int(input())
    s = input()
    k = int(input())

    print(cipher_caesar_string(s, k))
