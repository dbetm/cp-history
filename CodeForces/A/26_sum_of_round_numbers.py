# https://codeforces.com/problemset/problem/1352/A
# tags: math, implementation


def solve(n: int) -> None:
    n_str = str(n)
    power = 0
    ans = []

    for i in range(len(n_str) - 1, -1, -1):
        if n_str[i] != "0":
            ans.append(int(n_str[i]) * 10**power)

        power += 1

    print(len(ans))
    for num in ans:
        print(num, end=" ")

    print("")


if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        n = int(input())

        solve(n)