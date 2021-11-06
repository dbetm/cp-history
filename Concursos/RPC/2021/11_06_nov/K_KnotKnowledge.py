

if __name__ == '__main__':
    n = int(input())
    knots = list(map(int, input().split()))
    learned = list(map(int, input().split()))

    print(sum(knots) - sum(learned))
