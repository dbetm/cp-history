# https://www.hackerrank.com/challenges/two-characters/problem
# Tag(s): Strings, implementation
def is_valid(s, a, b):
    ans = True

    n = len(s)
    real_lenght = 0

    cont = 0
    for c in s:
        if c == a:
            break
        elif c == b:
            a, b = b, a
            break
        cont += 1

    flip = True

    for i in range(cont, n):
        if s[i] != a and s[i] != b:
            continue
        real_lenght += 1

        if flip:
            flip = False
            if s[i] != a:
                ans = False
                break
        else:
            flip = True
            if s[i] != b:
                ans = False
                break

    return (ans, real_lenght)


def alternate(s) -> int:
    ans = 0
    alphabet = set(s)
    letters = list(sorted(alphabet))
    n = len(letters)

    for i in range(n-1):
        for j in range(i+1, n):
            if letters[i] == letters[j]:
                continue
            validation = is_valid(s, letters[i], letters[j])
            if validation[0]:
                ans = max(validation[1], ans)

    return ans


if __name__ == '__main__':
    n = int(input())
    s = input()

    print(alternate(s))
