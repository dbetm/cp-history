# solved
# tags: implementation



def bestSeat(seats):
    """My solution:
    Time: O(n)
    Space: O(1)
    """
    index = 0
    n = len(seats)

    left = 0
    right = 0
    max_distance = 1
    current_distance = 1
    last_one = 0
    n = len(seats)

    for idx in range(1, n):
        if seats[idx] == 1:
            if current_distance > max_distance:
                left = last_one
                right = idx
                max_distance = current_distance

            last_one = idx
            current_distance = 1
        else:
            current_distance += 1

    if max_distance < 2:
        return -1

    index = left + (max_distance / 2) 

    return int(index)


if __name__ == "__main__":
    seats = list(map(int, input().split()))

    print(bestSeat(seats))
