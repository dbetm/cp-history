

if __name__ == '__main__':
    n = int(input())
    materials = set(map(int, input().split()))
    m = int(input())

    for _ in range(m):
        x = int(input())
        if x in materials:
            print("SI")
        else:
            print("NO")
