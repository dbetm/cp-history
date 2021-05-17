
def rotate_90(image):
    n = len(image)

    image = [[image[j][i] for j in range(n)] for i in range(n)]

    top = n-1
    buttom = 0
    while(top > buttom):
        image[top], image[buttom] = image[buttom], image[top]
        top -= 1
        buttom += 1

    # for i in range(n):
    #     image[i].reverse()

    return image

def rotate_90_v2(image):
    n = len(image)

    for layer in range(0, int(n/2)):
        first = layer
        last = n - 1 - layer

        for i in range(first, last):
            offset = i - first
            top = image[first][i]
            # left -> top
            image[first][i] = image[last-offset][first]

            # bottom -> left
            image[last-offset][first] = image[last][last-offset]

            # right -> bottom
            image[last][last-offset] = image[i][last]

            # top -> right
            image[i][last] = top # right <- saved top

    return image

if __name__ == '__main__':
    n = int(input("Type n: "))

    image = []

    for i in range(n):
        row = list(map(int, input().split()))
        image.append(row)

    print(rotate_90(image))
    print(rotate_90_v2(image))
