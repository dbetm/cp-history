# https://www.hackerrank.com/challenges/two-pluses/problem?isFullScreen=false
# tags: implementation, strings, matrix
from __future__ import annotations
from typing import List, Optional, Tuple



class Plus:
    def __init__(self, center_idx: Tuple[int, int], lenght: int, positions: set):
        self.center_idx = center_idx
        self.lenght = lenght
        self.area = 1 + (lenght * 4)
        self.positions = positions

    def intersect(self, another_plus: Plus) -> bool:
        # print(str(self), "||||||", str(another_plus))

        if self.center_idx == another_plus.center_idx:
            return True

        return len(self.positions.intersection(another_plus.positions)) > 0

    def intersect2(self, another_plus: Plus) -> bool:
        positions = {(self.center_idx)}

        for delta in range(1, self.lenght + 1):
            positions.add(
                (self.center_idx[0] + delta, self.center_idx[1])
            )
            positions.add(
                (self.center_idx[0] - delta, self.center_idx[1])
            )
            positions.add(
                (self.center_idx[0], self.center_idx[1] + delta)
            )
            positions.add(
                (self.center_idx[0], self.center_idx[1] - delta)
            )

        another_positions = {(another_plus.center_idx)}
        for delta in range(1, another_plus.lenght + 1):
            another_positions.add(
                (another_plus.center_idx[0] + delta, another_plus.center_idx[1])
            )
            another_positions.add(
                (another_plus.center_idx[0] - delta, another_plus.center_idx[1])
            )
            another_positions.add(
                (another_plus.center_idx[0], another_plus.center_idx[1] + delta)
            )
            another_positions.add(
                (another_plus.center_idx[0], another_plus.center_idx[1] - delta)
            )

        return len(positions.intersection(another_positions)) > 0

    def intersect3(self, another_plus: Plus) -> bool:
        r1, c1, L1 = self.center_idx[0], self.center_idx[1], self.lenght
        r2, c2, L2 = another_plus.center_idx[0], another_plus.center_idx[1], another_plus.lenght

        # V1 ∩ V2: misma columna, rangos de filas se solapan
        if c1 == c2 and r1 - L1 <= r2 + L2 and r2 - L2 <= r1 + L1:
            return True

        # H1 ∩ H2: misma fila, rangos de columnas se solapan
        if r1 == r2 and c1 - L1 <= c2 + L2 and c2 - L2 <= c1 + L1:
            return True

        # V1 ∩ H2: columna c1 dentro del rango horizontal de plus2, fila r2 dentro del rango vertical de plus1
        if c2 - L2 <= c1 <= c2 + L2 and r1 - L1 <= r2 <= r1 + L1:
            return True

        # H1 ∩ V2: columna c2 dentro del rango horizontal de plus1, fila r1 dentro del rango vertical de plus2
        if c1 - L1 <= c2 <= c1 + L1 and r2 - L2 <= r1 <= r2 + L2:
            return True

        return False

    def __str__(self) -> str:
        return str(self.center_idx) + " with lenght: " + str(self.lenght) + " " + str(self.positions)
        #return str(self.center_idx) + " with lenght: " + str(self.lenght)

    def print(self) -> None:
        print(str(self))

        size = self.lenght*2 + 1
        for i in range(size):
            for j in range(size):
                if (i == int(size / 2)) or (j == int(size / 2)):
                    print("*", end="")
                else:
                    print(" ", end="")
            print("")


def get_pluses(grid: list, i: int, j: int, n: int, m: int) -> Optional[List[Plus]]:
    up = i - 1
    down = i + 1
    right = j + 1
    left = j - 1
    lenght = 0
    pluses = [Plus((i, j), lenght=0, positions={(i, j)})]
    #positions = {(i, j)}

    while (
        up >= 0 and down < n and left >= 0 and right < m and grid[i][right] == "G"
        and grid[i][left] == "G" and grid[up][j] == "G" and grid[down][j] == "G"
    ):
        lenght += 1
        # positions.add((i, right))
        # positions.add((i, left))
        # positions.add((up, j))
        # positions.add((down, j))

        #if lenght % 2 == 0:
        # pluses.append(Plus((i, j), lenght, positions.copy()))
        pluses.append(Plus((i, j), lenght, {}))

        up -= 1
        down += 1
        left -= 1
        right += 1

    return pluses


def get_max_product(pluses: List[Plus]) -> int:
    max_product = -100000000
    n = len(pluses)

    for i in range(n - 1):
        for j in range(i + 1, n):
            if not pluses[i].intersect3(pluses[j]):
                product = pluses[i].area * pluses[j].area

                if product > max_product:
                    max_product = product
            else:
                pass
                # if pluses[i].lenght == 2 and pluses[j].lenght == 2:
                #     print(f"{str(pluses[i])} intersects {str(pluses[j])}")

    return max_product


def get_max_two_pluses(grid: list, n: int, m: int) -> int:
    number_good_cells = 0
    pluses: List[Plus] = list()

    for i in range(n):
        for j in range(m):
            if grid[i][j] == "G":
                number_good_cells += 0

                candidates = get_pluses(grid, i, j, n, m)

                pluses += candidates

                #print(str(candidate))

    # for plus in pluses:
    #     plus.print()

    return get_max_product(pluses)



if __name__ == '__main__':

    n, m = map(int, input().split(" "))

    grid = list()

    for _ in range(n):
        row = list(input())
        grid.append(row)


    print(get_max_two_pluses(grid, n, m))
