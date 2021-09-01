# https://www.hackerrank.com/challenges/itertools-combinations-with-replacement/problem

from itertools import combinations_with_replacement

if __name__ == '__main__':
    string, k = input().split()
    k = int(k)
    string = sorted(string)

    combinations = sorted(combinations_with_replacement(string, k))

    for comb in combinations:
        print(''.join(comb))
