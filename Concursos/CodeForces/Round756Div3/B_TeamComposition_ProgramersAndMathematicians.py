# https://codeforces.com/contest/1611/problem/B
# Tag(s):

if __name__ == '__main__':
    t = int(input())

    for i in range(t):
        a, b = list(map(int, input().split()))

        total = a + b
        max_num_teams = total // 4

        if a == b:
            ans = a // 2
        else:
            ans = min(a, b)

        ans = min(max_num_teams, ans)

        print(ans)
