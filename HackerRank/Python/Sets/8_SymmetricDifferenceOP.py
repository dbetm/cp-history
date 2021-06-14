# https://www.hackerrank.com/challenges/py-set-symmetric-difference-operation/problem

if __name__ == '__main__':
    e = int(input())
    english_rolls = set(map(int, input().split(' ')))
    f = int(input())
    french = set(map(int, input().split(' ')))

    print(len(english_rolls.symmetric_difference(french)))
