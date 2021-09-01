from collections import defaultdict

# https://www.hackerrank.com/challenges/defaultdict-tutorial/problem

if __name__ == '__main__':
    n, m = list(map(int, input().split()))

    d = defaultdict(list)

    for i in range(1, n+1):
        character = input()
        d[character].append(i)

    for _ in range(m):
        character = input()

        if len(d[character]) > 0:
            aux = d[character]
            for position in aux:
                print(position, end=' ')
            print('')
        else:
            print(-1)
