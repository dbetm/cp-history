# https://www.hackerrank.com/challenges/missing-numbers/problem
# tags: search, map


if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split(" ")))
    m = int(input())
    brr = list(map(int, input().split(" ")))

    brr_map = dict()

    for num in brr:
        if num in brr_map:
            brr_map[num] += 1
        else:
            brr_map[num] = 1

    arr_map = dict()

    for num in arr:
        if num in arr_map:
            arr_map[num] += 1
        else:
            arr_map[num] = 1
    
    answers = list()
    
    for num, freq in brr_map.items():
        if num not in arr_map or freq != arr_map[num]:
            answers.append(num)

    answers.sort()


    for x in answers:
        print(x, end=" ")
    print("")