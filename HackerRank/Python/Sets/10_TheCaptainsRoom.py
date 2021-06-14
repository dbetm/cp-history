# https://www.hackerrank.com/challenges/py-the-captains-room/problem

if __name__ == '__main__':
    k = int(input())
    room_numbers = list(map(int, input().split()))
    n = len(room_numbers)

    room_numbers = sorted(room_numbers)
    left = []
    right = []
    flip = True

    for i in range(n):
        if flip:
            left.append(room_numbers[i])
        else:
            right.append(room_numbers[i])
        flip = not flip


    print(set(left).symmetric_difference(set(right)).pop())
