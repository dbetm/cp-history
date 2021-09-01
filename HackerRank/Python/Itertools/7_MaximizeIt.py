# https://www.hackerrank.com/challenges/maximize-it/problem

from itertools import product

def evaluate(x, m):
    res = sum(((x_i % m)*(x_i % m)) % m for x_i in x)
    return res % m

if __name__ == '__main__':
    k, m = list(map(int, input().split()))

    B = []

    for i in range(k):
        n, *aux = input().split()
        aux = list(map(int, aux))
        B.append(aux)

    res = list(product(*B))

    ans = 0

    for item in res:
        res = evaluate(item, m)
        if res > ans:
            ans = res

    print(ans)
