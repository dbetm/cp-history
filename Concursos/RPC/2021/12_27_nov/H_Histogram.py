# AC

if __name__ == '__main__':
    n, s, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))

    arr.sort()

    heights = [0] * n

    factor = 1
    for x in arr:
        if x > (factor * s):
            while x > (factor * s):
                factor += 1
        heights[factor - 1] += 1

    rectangle = []
    max_h = max(heights)

    for i in range(n):
        bar = ['-']
        for _ in range(heights[i]):
            bar.append('#')

        for _ in range(max_h - heights[i]):
            bar.append('.')

        rectangle.append(bar)

    for j in range(max_h, -1, -1):
        for i in range(n):
            print(rectangle[i][j], end='')
        print("")
