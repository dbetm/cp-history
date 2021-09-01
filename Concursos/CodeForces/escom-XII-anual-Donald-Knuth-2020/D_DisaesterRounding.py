import math

n = int(input(""))
M = 1e9 + 7

x = n // 2
delta = (n % 2) * x
sum = delta % M

for l in range(x-1, 0, -1):
    sum = (int(sum) + l*2) % M
    # print(k, ": ", int(sum))
    # if(k > 1):
    #     print(y[k], y[k-1], y[k] / y[k-1])

print(int(sum))
