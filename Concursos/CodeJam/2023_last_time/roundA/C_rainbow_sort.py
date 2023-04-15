# solved
# Tag(s): implementation, maps

def print_color_set(color_id_map: dict, case: int):
    id_color_map = {value: str(key) for key, value in color_id_map.items()}

    sorted_map = dict(sorted(id_color_map.items()))

    print(f"Case #{case}:", " ".join(sorted_map.values()))


if __name__  == "__main__":
    t = int(input())

    for i in range(1, t+1):
        n = int(input())
        last_color = -1
        id_to_assign = 1
        color_id_map = dict()
        is_impossible = False
        colors = list(map(int, input().split(" ")))

        for color in colors:
            if color == last_color:
                continue
            if color in color_id_map:
                is_impossible = True
                break

            color_id_map[color] = id_to_assign
            id_to_assign += 1
            last_color = color


        if is_impossible:
            print(f"Case #{i}: IMPOSSIBLE")
        else:
            print_color_set(color_id_map, i)

