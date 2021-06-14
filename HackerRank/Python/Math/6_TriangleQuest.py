# https://www.hackerrank.com/challenges/python-quest-1/problem

for i in range(1,int(input())): #More than 2 lines will result in 0 score. Do not leave a blank line also
    print(i * ( int(pow(10, i-1)) + int(pow(10, i-2)) + int(pow(10, i-3)) + int(pow(10, i-4)) + int(pow(10, i-5)) + int(pow(10, i-6)) + int(pow(10, i-7)) + int(pow(10, i-8)) + int(pow(10, i-9))))

"""
Alternatives:
1.
for i in range(1,input()):
    print i * sum(map(lambda x: 10 ** x, range(i)))

2.
print((10**i)//9*i)

"""
