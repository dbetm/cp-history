from typing import Union


def compute_distance(coord_a: tuple, coord_b: tuple) -> Union[float, int]:
    if coord_a[0] < 0 or coord_a[1] < 0 or coord_b[0] < 0 or coord_b[1] < 0:
        return float("inf")

    return abs(coord_a[0] - coord_b[0]) + abs(coord_a[1] - coord_b[1])


MOVEMENTS = (
    (-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1)
)


def has_capured(coord_a: tuple, coord_b: tuple):
    return coord_a[0] == coord_b[0] and coord_a[1] == coord_b[1]



def update_coord(current_coord, coord_to_cmp):
    distance = float("inf")
    new_coord_a = None

    for deltas in MOVEMENTS:
        coord = (current_coord[0] + deltas[0], current_coord[1] + deltas[1])

        tmp_distance = compute_distance(coord, coord_to_cmp)

        if tmp_distance < distance:
            distance = tmp_distance
            new_coord_a = coord

    return new_coord_a


import time

def knightConnection(knightA, knightB):
    turns = 0
    coord_a = (knightA[0], knightA[1])
    coord_b = (knightB[0], knightB[1])

    if has_capured(coord_a, coord_b):
        return turns

    while True:
        turns += 1
        print(f"{coord_a=}", f"{coord_b=}")
        coord_a = update_coord(coord_a, coord_b)

        if has_capured(coord_a, coord_b):
            break

        coord_b = update_coord(coord_b, coord_a)

        if has_capured(coord_a, coord_b):
            break

        time.sleep(2)

    return turns



if __name__ == "__main__":
    knight_a = list(map(int, input().split(" ")))
    knight_b = list(map(int, input().split(" ")))

    print(knightConnection(knight_a, knight_b))