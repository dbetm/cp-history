# https://codeforces.com/contest/1133/problem/C
# tag(s): pointers

def getMaxNumMembers(n, team):
    team = sorted(team)
    a = 0
    b = 0
    ans = 1
    cont = 1

    while b < n:
        if (b+1) < n and abs(team[b+1] - team[a]) <= 5:
            cont += 1
            b += 1

            if ans < cont:
                ans = cont
        else:
            cont = max(1, cont - 1)
            a += 1

            if a > b:
                b = a

    return ans

if __name__ == '__main__':
    n = int(input())
    team = map(int, input().split())

    print(getMaxNumMembers(n, team))
