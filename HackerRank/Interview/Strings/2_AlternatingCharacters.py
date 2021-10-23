# https://www.hackerrank.com/challenges/alternating-characters/problem
# Tag(s): Greedy, strings

def alternatingCharacters(s):
    flag_1 = 'A'
    flag_2 = 'B'
    x = 0
    y = 0

    n = len(s)

    for i in range(n):
        if s[i] == flag_1:
            flag_1 = ('B' if flag_1 == 'A' else 'A')
        else:
            x += 1

        if s[i] == flag_2:
            flag_2 = ('B' if flag_2 == 'A' else 'A')
        else:
            y += 1

    return min(x, y)



if __name__ == '__main__':
    T = int(input())

    for _ in range(T):
        s = input()
        print(alternatingCharacters(s))
