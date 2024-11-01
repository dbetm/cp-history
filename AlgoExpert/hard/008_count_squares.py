# solved
# tags: math, implementation, geometry


def get_diffs_points(a: list, b: list):
    assert len(a) == 2 and len(b) == 2

    x_delta = abs(a[0] - b[0])
    y_delta = abs(a[1] - b[1])

    return x_delta, y_delta


def has_flipped(delta_a: list, delta_b: list):
    assert len(delta_a) == 2 and len(delta_b) == 2

    return delta_a[0] == delta_b[1] and delta_a[1] == delta_b[0]


def countSquares(points: list):
    """My solution
    Time: O(n^4)
    Space: O(n)
    """
    squares = set()
    n = len(points)

    for idx in range(n):
        for jdx in range(n):
            if idx == jdx:
                continue

            x_delta_1, y_delta_1 = get_diffs_points(points[idx], points[jdx])
            for kdx in range(n):
                if kdx in (idx, jdx):
                    continue

                x_delta_2, y_delta_2 = get_diffs_points(points[jdx], points[kdx])

                if has_flipped([x_delta_1, y_delta_1], [x_delta_2, y_delta_2]):
                    for ldx in range(n):
                        if ldx in (idx, jdx, kdx):
                            continue

                        x_delta_3, y_delta_3 = get_diffs_points(points[kdx], points[ldx])

                        if has_flipped([x_delta_2, y_delta_2], [x_delta_3, y_delta_3]):
                            x_delta_4, y_delta_4 = get_diffs_points(points[ldx], points[idx])

                            if has_flipped([x_delta_4, y_delta_4], [x_delta_3, y_delta_3]):

                                square = list()
                                for index in [idx, jdx, kdx, ldx]:
                                    square.append(tuple(points[index]))

                                square.sort()
                                squares.add(tuple(square))

    # print(f"{squares=}")

    return len(squares)



def get_midpoint(point1: list, point2: list) -> tuple:
    assert len(point1) == 2 and len(point2) == 2

    return ((point1[0] + point2[0]) / 2, (point1[1] + point2[1]) / 2)



def get_slopes(point: list, midpoint: tuple) -> tuple:
    assert len(point) == 2 and len(midpoint) == 2

    return (point[0] - midpoint[0], point[1] - midpoint[1])



def point_to_string(point: list) -> str:
    # if it's integer, drop the possible ".0"
    if point[0] % 1 == 0 and point[1] % 1 == 0:
        point = [int(coordinate) for coordinate in point]

    return ",".join([str(coordinate) for coordinate in point])



def countSquares2(points: list):
    """Proposal
    Time: O(n^2)
    Space: O(n)

    We will check each pair of points and assume that they are forming a diagonal from an existing square.
    Then we will check if exist another pair of points, using the following:
    1) Compute the midpoint between the selected pair.
    2) Compute the slope for the X and Y coordinates.
    3) Check if (midpoint_x + slope_x, midpoint_y - slope_y) and (midpoint_x - slope_x, midpoint_y + slope_y) exist.

    Since we are counting each square 4 times, we need to divide the final answer by 4.
    """
    n = len(points)
    set_points = set()
    num_squares = 0

    for point in points:
        set_points.add(point_to_string(point))

    # print(f"{set_points=}")

    for idx in range(n):
        for jdx in range(n):
            if idx == jdx:
                continue

            midpoint = get_midpoint(points[idx], points[jdx])
            slopes = get_slopes(points[idx], midpoint)

            third_pt = (midpoint[0] + slopes[1], midpoint[1] - slopes[0])
            fourth_pt = (midpoint[0] - slopes[1], midpoint[1] + slopes[0])

            if point_to_string(third_pt) in set_points and point_to_string(fourth_pt) in set_points:
                # print(f"{midpoint=}", f"{slopes=}", points[idx], points[jdx], third_pt, fourth_pt)

                num_squares += 1

    return num_squares // 4


if __name__ == "__main__":
    n = int(input())
    points = list()

    for i in range(n):
        point = list(map(int, input().split()))
        points.append(point)

    print(countSquares2(points))
