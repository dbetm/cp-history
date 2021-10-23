# https://www.hackerrank.com/challenges/frequency-queries/problem
# Tag(s): HashMap, sets, data structures

elements = dict()
ocurrences = dict()

def insert_occurence(x, val):
    if not x in ocurrences:
        ocurrences[x] = set()

    ocurrences[x].add(val)

def delete_occurence(x, val):

    if x in ocurrences:
        ocurrences[x].remove(val)

        if len(ocurrences[x]) == 0:
            del ocurrences[x]

def insert_element(x):
    if x in elements:
        delete_occurence(elements[x], x)
        elements[x] += 1
        insert_occurence(elements[x], x)
    else:
        elements[x] = 1
        insert_occurence(1, x)

def delete_element(x):
    if x in elements:
        delete_occurence(elements[x], x)
        elements[x] -= 1
        if elements[x] == 0:
            del elements[x]
        else:
            insert_occurence(elements[x], x)

if __name__ == '__main__':
    q = int(input())

    for _ in range(q):
        op, val = list(map(int, input().split()))

        if op == 1:
            insert_element(val)
        elif op == 2:
            delete_element(val)
        else:
            print('1' if (val in ocurrences) else '0')
