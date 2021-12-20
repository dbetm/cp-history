# https://www.hackerrank.com/challenges/anagram/problem
# Tag(s): strings, dictionaries

def compute(s):
    n = len(s)
    if n & 1:
        return -1

    left = s[0:n//2]
    right = s[n//2:n]

    map_1 = {}
    map_2 = {}

    for i in range(len(left)):
        if left[i] in map_1:
            map_1[left[i]] += 1
        else:
            map_1[left[i]] = 1

        if right[i] in map_2:
            map_2[right[i]] += 1
        else:
            map_2[right[i]] = 1

    # reduce same characters
    for key, value in map_1.items():
        if key in map_2:
            if value == map_2[key]:
                map_1[key] = 0
                map_2[key] = 0
            elif value > map_2[key]:
                map_1[key] = value - map_2[key]
                map_2[key] = 0
            else:
                map_2[key] = map_2[key] - value
                map_1[key] = 0

    cont = 0

    for key, value in map_1.items():
        cont += value

    return cont


if __name__ == '__main__':
    q = int(input())

    for i in range(q):
        s = input()
        print(compute(s))
