# https://www.hackerrank.com/challenges/count-triplets-1/problem
# tag(s): HashMap, maths

def countTriplets(arr, r):
    right = dict()
    left = dict()
    ans = 0

    for x in arr:
        if x in right:
            right[x] += 1
        else:
            right[x] = 1

    for x in arr:
        right[x] -= 1

        if (x * r) in right:
            c1 = right[x * r]

            if (x / r) in left:
                c2 = left[x / r]

                ans += c1 * c2

        if x in left:
            left[x] += 1
        else:
            left[x] = 1

    return ans

cases = [
    {'arr': [1, 2, 2, 4], 'r': 2, 'ans': 2},
    {'arr': [1, 3, 9, 9, 27, 81], 'r': 3, 'ans': 6},
    {'arr': [1, 5, 5, 25, 125], 'r': 5, 'ans': 4},
    {'arr': [1, 1, 1, 1], 'r': 1, 'ans': 4},
]

def run_tests():
    correct = 0
    for i, test in enumerate(cases):
        calculated = countTriplets(test['arr'], test['r'])

        if calculated == test['ans']:
            correct += 1
        else:
            print("ERROR in case: {}".format(i))
            print(test)
            print("Calculated: {}".format(calculated))
            print("\n")

    print(correct, "/", len(cases))


if __name__ == '__main__':
    run_tests()
    n, r = list(map(int, input().split()))
    arr = list(map(int, input().split())) # unordered array

    print(countTriplets(arr, r))
