# https://www.hackerrank.com/challenges/two-strings/problem
# Tag(s): hashmaps, strings

def twoStrings(s1:str, s2:str):
    letters = [False] * 26

    for c in s1:
        letters[ord(c)-97] = True

    for c in s2:
        if letters[ord(c)-97]:
            return True

    return False


if __name__ == '__main__':
    p = int(input())

    for i in range(p):
        s1 = input()
        s2 = input()
        print('YES' if twoStrings(s1, s2) else 'NO')
