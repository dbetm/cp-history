


def hour_glass_max_sum(array: list) -> int:
    max_sum = float("-inf")

    for i in range(0, 4):
        for j in range(0, 4):
            a = array[i][j]
            b = array[i][j+1]
            c = array[i][j+2]
            d = array[i+1][j+1]
            e = array[i+2][j]
            f = array[i+2][j+1]
            g = array[i+2][j+2]

            sum_ = a + b + c + d + e + f + g

            if max_sum < sum_:
                max_sum = sum_

    return int(max_sum)

if __name__ == "__main__":
    array = list()


    for _ in range(6):
        row = list(map(int, input("").split(" ")))
        array.append(row)


    print(hour_glass_max_sum(array))

