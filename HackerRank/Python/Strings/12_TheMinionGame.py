# !/usr/bin/env python3
# https://www.hackerrank.com/challenges/the-minion-game/problem
# tag(s): cadenas

def minion_game(string):
    stuart = 0
    kevin = 0
    i = len(string)
    for chr in string:
        if(chr == 'A' or chr == 'E' or chr == 'I' or chr == 'O' or chr == 'U'):
            kevin += i
        else:
            stuart += i
        i -= 1

    if(stuart > kevin):
        print("Stuart", stuart)
    elif(stuart == kevin):
        print("Draw")
    else:
        print("Kevin", kevin)

if __name__ == '__main__':
    s = input()
    minion_game(s)
