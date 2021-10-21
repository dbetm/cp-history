# https://www.hackerrank.com/challenges/ctci-ransom-note/problem
# Tag(s): HashMap, implemetation

def checkMagazine(magazine, note):
    if len(note) > len(magazine):
        return False

    magazine_dict = dict()
    ans = True

    for m in magazine:
        if m in magazine_dict:
            magazine_dict[m] += 1
        else:
            magazine_dict[m] = 1

    for word in note:
        if not word in magazine_dict:
            ans = False
            break
        else:
            magazine_dict[word] -= 1

            if magazine_dict[word] == 0:
                del magazine_dict[word]

    return ans


if __name__ == '__main__':
    m, n = list(map(int, input().split()))
    magazine = input().split()
    note = input().split()

    if checkMagazine(magazine, note):
        print("Yes")
    else:
        print("No")
