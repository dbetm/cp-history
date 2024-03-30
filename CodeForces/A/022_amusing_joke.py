# https://codeforces.com/problemset/problem/141/A
# tags: map, string


if __name__ == "__main__":
    guest_name = input("")
    host_bame = input("")
    pile = input("")

    names_map = dict()
    pile_map = dict()

    for c in guest_name:
        if c not in names_map:
            names_map[c] = 1
        else:
            names_map[c] += 1
    
    for c in host_bame:
        if c not in names_map:
            names_map[c] = 1
        else:
            names_map[c] += 1

    for c in pile:
        if c not in pile_map:
            pile_map[c] = 1
        else:
            pile_map[c] += 1

    if names_map == pile_map:
        print("YES")
    else:
        print("NO")