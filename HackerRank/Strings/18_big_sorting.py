# https://www.hackerrank.com/challenges/big-sorting/problem
# tag(s): strings, sorting


if __name__ == "__main__":
    n = int(input())

    items_per_len = dict()

    for _ in range(n):
        x = input()

        if len(x) not in items_per_len:
            items_per_len[len(x)] = [x]
        else:
            items_per_len[len(x)].append(x)

    for _, vals in dict(sorted(items_per_len.items())).items():
        vals.sort()

        for val in vals:
            print(val)

