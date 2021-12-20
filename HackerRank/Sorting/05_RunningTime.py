# https://www.hackerrank.com/challenges/runningtime/problem
# Tag(s): sorting

def insertion_sort(l):
    num_shifts = 0
    for i in range(1, len(l)):
        j = i-1
        key = l[i]
        while (j >= 0) and (l[j] > key):
           l[j+1] = l[j]
           j -= 1
           num_shifts += 1
        l[j+1] = key

    print(num_shifts)

m = int(input().strip())
ar = [int(i) for i in input().strip().split()]
insertion_sort(ar)
