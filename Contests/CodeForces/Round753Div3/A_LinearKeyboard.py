# https://codeforces.com/contest/1607/problem/A
# Tag(s): strings, implementation

def compute_long(keyboard, word):
    ans = 0
    m = len(word)

    alphabet = {}

    for i, key in enumerate(keyboard):
        alphabet[key] = i

    for i in range(1, m):
        ans += abs(alphabet[word[i-1]] - alphabet[word[i]])

    return ans


if __name__ == '__main__':
    t = int(input())

    for i in range(t):
        keyboard = input()
        word = input()

        print(compute_long(keyboard, word))
