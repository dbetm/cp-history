from collections import namedtuple

# https://www.hackerrank.com/challenges/py-collections-namedtuple/problem

if __name__ == '__main__':
    n = int(input())
    columns = input()
    Student = namedtuple('Student', columns)

    total = 0.

    for _ in range(n):
        vals = input().split()
        student = Student(*vals)
        total += float(student.MARKS)

    print('{:.2f}'.format(total / n))
