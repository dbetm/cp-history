# https://www.hackerrank.com/challenges/triangle-quest-2/problem

for i in range(1,int(input())+1): #More than 2 lines will result in 0 score. Do not leave a blank line also
    print(int(10**i // 9)**2)
