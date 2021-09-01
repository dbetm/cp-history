# https://www.hackerrank.com/challenges/compress-the-string/problem

from itertools import groupby

if __name__ == '__main__':
    S = input()

    modified_S = groupby(S)

    for group in modified_S:
        print('({}, {})'.format(len(list(group[1])), group[0]), sep=" ", end=" ")
