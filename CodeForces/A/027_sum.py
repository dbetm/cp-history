# solved
# tags: implementation


def check(a: int, b: int, c: int):
    ans = False

    if (a + b) == c:
        ans = True
    elif (a + c) == b:
        ans = True
    elif (b + c) == a:
        ans = True

    if ans:
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    t = int(input(""))

    for _ in range(t):
        a, b, c = list(map(int, input().split()))
        check(a, b, c)
