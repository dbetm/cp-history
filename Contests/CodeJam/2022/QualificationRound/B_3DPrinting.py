NUM_COLOR_CHANNELS = 4
MAX_UNITS = int(1e6)
# TEST #1: AC


def compute(printers) -> str:
    ans = []

    res = MAX_UNITS
    for j in range(NUM_COLOR_CHANNELS):
        min_units = min([channels[j] for channels in printers])

        if min_units <= res:
            res -= min_units
            ans.append(min_units)
        else:
            ans.append(res)
            res = 0

    if sum(ans) < MAX_UNITS:
        return "IMPOSSIBLE"

    return " ".join(map(str, ans))


if __name__ == '__main__':
    t = int(input())

    for i in range(t):
        printers = []
        for _ in range(3):
            cartridges = list(map(int, input().split()))
            printers.append(cartridges)

        print(f"Case #{i+1}: {compute(printers)}")
