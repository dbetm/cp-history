# https://www.hackerrank.com/challenges/happy-ladybugs/problem?
# Tag(s): Implementation

def all_happy_ladybugs(B):
    n = len(B)

    if n == 1:
        if B[0] == '_':
            return 'YES'
        else:
            return "NO"

    all_happy = True
    for x in range(n):
        if x > 0 and x < (n-1) and (B[x] != B[x+1] and B[x] != B[x-1]):
            all_happy = False
            break
        elif x == 0 and B[x] != B[x+1]:
            all_happy = False
            break
        elif x == (n-1) and B[x] != B[x-1]:
            all_happy = False
            break

    if all_happy:
        return "YES"

    num_underscores = 0
    mapping = {}

    for x in B:
        if x == '_':
            num_underscores += 1
        elif not x in mapping:
            mapping[x] = 1
        else:
            mapping[x] += 1

    if num_underscores == 0:
        return "NO"

    ans = 'YES'

    for key, value in mapping.items():
        if value == 1:
            ans = 'NO'
            break

    return ans



if __name__ == '__main__':
    g = int(input())

    for i in range(g):
        n = int(input())
        B = list(input())

        print(all_happy_ladybugs(B))
