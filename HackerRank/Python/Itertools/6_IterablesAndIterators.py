from itertools import combinations

# https://www.hackerrank.com/challenges/iterables-and-iterators/problem

if __name__ == '__main__':
    n = int(input())
    letters = tuple(input().split())
    k = int(input())

    _combinations = list(combinations(range(1, len(letters) + 1), r=k))

    total = len(_combinations)
    num_as = 0

    for p in _combinations:
        # print(p)
        for i in p:
            if letters[i-1] == 'a':
                num_as += 1
                break

    result = float(num_as / total)
    print('{:.3f}'.format(result))
