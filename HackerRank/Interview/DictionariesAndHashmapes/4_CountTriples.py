#
# tag(s):

def countTriplets(arr, r):
    # possible fix: computing while creating the map iterating from n-1 to 0
    # update: we need to make sure that j < k,
        # first compute j < k, arr[j]*r  < arr[k]*r²
        # then compute i < j, arr[i] < arr[j]*r
    ans = 0
    n = len(arr)

    all_elements = dict()

    pre_1 = dict()

    if n < 3:
        return ans

    if r == 1:
        pass
    else:
        for i in range(n-1, -1, -1):
            x = arr[i] * r

            if x in pre_1:

            if x in all_elements:
                all_elements[x] += 1
            else:
                all_elements[x] = 1

    if r == 1:
        for x in arr:
            if x in all_elements:
                all_elements[x] += 1
            else:
                all_elements[x] = 1
        for element, count in all_elements.items():
            if count < 3:
                continue
            ans += ((count) * (count-1) * (count-2)) // 6
    else:
        for i in range(n-1, -1, -1):
            x = arr[i] * r

            if x in all_elements:
                aux = all_elements[x]
                x *= r
                if x in all_elements:
                    ans += aux * all_elements[x]

            if arr[i] in all_elements:
                all_elements[arr[i]] += 1
            else:
                all_elements[arr[i]] = 1

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
    #run_tests()
    n, r = list(map(int, input().split()))
    arr = list(map(int, input().split())) # unordered array

    print(countTriplets(arr, r))
