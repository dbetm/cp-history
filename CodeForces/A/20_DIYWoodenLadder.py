# https://codeforces.com/problemset/problem/1197/A
# tag(s): Implementation, sorting

def compute_max_ladder(lens):
    ans = 0
    lens = sorted(lens, reverse=True)

    if len(lens) == 2 or (lens[0] == 1 or lens[1] == 1):
        return ans

    ans = min(lens[1] - 1, len(lens) - 2)


    return ans


if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        n = int(input())
        lens = list(map(int, input().split()))

        print(compute_max_ladder(lens))
