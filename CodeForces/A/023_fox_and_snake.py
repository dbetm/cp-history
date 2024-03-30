# https://codeforces.com/problemset/problem/510/A
# tags: implementation


def draw_snake(n: int, m: int):
    flag_left = False

    for i in range(1, n+1):
        for j in range(m):
            if i & 1: # odd row
                print("#", end="")
            else:
                if j == 0 and not flag_left:
                    print("#", end="")
                elif j == (m-1) and flag_left:
                    print("#", end="")
                else:
                    print(".", end="")
        print("")

        if i & 1:
            flag_left = not flag_left


if __name__ == "__main__":
    n, m = list(map(int, input("").split(" ")))

    draw_snake(n, m)