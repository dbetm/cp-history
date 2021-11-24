# https://www.hackerrank.com/challenges/flatland-space-stations/problem
# Tag(s): implementation, data structures

if __name__ == '__main__':
    n, m = list(map(int, input().split()))

    space_stations = set(map(int, input().split()))
    cities = list(range(n))

    ans = 0
    flag = False
    cont = 0
    for city in cities:
        if city in space_stations:
            if not flag:
                ans = max(ans, cont)
                flag = True
            else:
                ans = max(ans, (cont + 1) // 2)
            cont = 0
        else:
            cont += 1

    ans = max(ans, cont)

    print(ans)
