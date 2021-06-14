# https://www.hackerrank.com/challenges/no-idea/problem

if __name__ == '__main__':
    aux = list(map(int, input().split()))
    array = list(map(int, input().split()))

    a = set(map(int, input().split()))
    b = set(map(int, input().split()))

    happiness = 0
    counts = dict()

    for i in range(len(array)):
        if counts.get(array[i], '-1') != '-1':
            counts[array[i]] += 1
        else:
            counts[array[i]] = 1

    for i in counts:
        if i in a:
            happiness += counts[i]
        elif i in b:
            happiness -= counts[i]

    print(happiness)
