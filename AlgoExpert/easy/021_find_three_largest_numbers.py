# solved
# tags: implementation


def findThreeLargestNumbers(array):
    """My solution:
    Time: O(n)
    Space: O(1)
    """
    c, b, a = sorted([array[0], array[1], array[2]])

    for idx, x in enumerate(array):
        if idx < 3:
            continue

        if x > c and x > b and x > a:
            c = b
            b = a
            a = x
        elif x > c and x > b:
            c = b
            b = x
        elif x > c:
            c = x

    return [c, b, a]


if __name__ == '__main__':  
    arr = list(map(int, input().split()))

    print(findThreeLargestNumbers(arr))
