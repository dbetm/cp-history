# https://codeforces.com/contest/1611/problem/A
# Tag(s):
def compute(n):
    if not int(n[-1]) & 1:
        return 0

    i = 0
    while True:
        if not int(n[i]) & 1:
            break
        i += 1

        if i == len(n):
            return -1


    return 1 if i < 1 else 2

if __name__ == '__main__':
    t = int(input())

    for i in range(t):
        n = input()
        print(compute(n))
