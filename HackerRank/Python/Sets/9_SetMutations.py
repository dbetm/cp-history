# https://www.hackerrank.com/challenges/py-set-mutations/problem

if __name__ == '__main__':
    m = int(input())
    A = set(map(int, input().split()))
    n = int(input())

    for _ in range(n):
        name, x_n = input().split()
        Bx = set(map(int, input().split()))

        if name == 'update':
            A.update(Bx)
        elif name == 'intersection_update':
            A.intersection_update(Bx)
        elif name == 'difference_update':
            A.difference_update(Bx)
        else:
            A.symmetric_difference_update(Bx)

    print(sum(A))
