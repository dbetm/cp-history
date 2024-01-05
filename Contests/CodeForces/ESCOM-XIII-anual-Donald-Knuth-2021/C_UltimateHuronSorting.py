# accepted

if __name__ == '__main__':
    n = int(input())

    perm = list(map(int, input().split()))

    num_xs = 0

    for idx, num in enumerate(perm):
        if (idx + 1) == num:
            num_xs += 1

    print(num_xs)
