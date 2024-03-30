# https://codeforces.com/problemset/problem/427/A
# tags: implementation

CRIME_EVENT = -1


if __name__ == "__main__":
    n = int(input(""))

    events = list(map(int, input("").split(" ")))
    available_policies = 0
    untreated_crimes = 0

    for event in events:
        if event == CRIME_EVENT:
            if available_policies == 0:
                untreated_crimes += 1
            else:
                available_policies -= 1
        else:
            available_policies += event

    print(untreated_crimes)


