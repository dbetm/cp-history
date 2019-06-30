from decimal import Decimal
# https://omegaup.com/arena/problem/Factorizar-de-ASINUS#problems
def factorial(n):
    if(n <= 1):
        return 1
    else:
        return n * factorial(n-1)

if __name__ == '__main__':
    n = int(raw_input())
    res = factorial(n)
    if(res > 10000):
        res = '%.5E' % Decimal(res)
    print(res)
