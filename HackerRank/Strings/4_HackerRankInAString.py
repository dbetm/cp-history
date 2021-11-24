# https://www.hackerrank.com/challenges/hackerrank-in-a-string/problem
# Tag(s): Strings

def hackerRankInString(s:str) -> bool:
    base_word = 'hackerrank'
    ptrs = []
    ans = False

    n = len(s)

    for c in s:
        if base_word[0] == c:
            ptrs.append(0)

        for x in range(len(ptrs)):
            if base_word[ptrs[x]] == c:
                ptrs[x] += 1
                if c == 'k' and ptrs[x] == 10:
                    ans = True
                    break
        else:
            continue
        break

    # print(ptrs)

    return ans


if __name__ == '__main__':
    q = int(input())

    for i in range(q):
        s = input()

        print('YES' if hackerRankInString(s) else 'NO')
