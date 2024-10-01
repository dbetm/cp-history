import math
from typing import Union



def is_the_same_position(a: Union[list, tuple], b: Union[list, tuple]) -> bool:
    NUM_DIMS = 2
    assert len(a) >= NUM_DIMS
    assert len(b) >= NUM_DIMS

    return a[0] == b[0] and a[1] == b[1]


def knightConnection(knightA, knightB):
    """Proposal
    Time: O(n * m)
    Space: O(n * m)

    Where n is the horizontal distance between the knights and m the vertical one.
    """
    deltas = [
        (-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1)
    ]
    # coordinate of knight and the distance in rounds to the another knight
    position = (knightA[0], knightA[1], 0)
    visited_positions = {(position[0], position[1])}
    next_movements = [position]

    while True:
        position = next_movements.pop(0)

        if is_the_same_position(position, knightB):
            return math.ceil(position[2] / 2)

        for delta in deltas:
            new_pos = (position[0] + delta[0], position[1] + delta[1])

            if new_pos in visited_positions:
                continue

            visited_positions.add(new_pos)
            next_movements.append((new_pos[0], new_pos[1], position[2] + 1))



if __name__ == "__main__":
    knight_a = list(map(int, input().split(" ")))
    knight_b = list(map(int, input().split(" ")))

    print(knightConnection(knight_a, knight_b))