# solved
# tags: implementation, simulation


def process(arrangment: list) -> str:
    n = len(arrangment)
    i = 1

    while i < n:
        if arrangment[i] == 'G' and arrangment[i-1] == 'B':
            arrangment[i], arrangment[i-1] = arrangment[i-1], arrangment[i]
            i += 1

        i += 1


if __name__ == "__main__":
    n, t = list(map(int, input().split()))
    queue = list(input())

    for i in range(t):
        process(queue)

    print("".join(queue))
