# solved
# tags: implementation


def classPhotos(redShirtHeights, blueShirtHeights):
    """My solution
    Time: O(n log(n))
    Space: O(1)
    """
    redShirtHeights.sort()
    blueShirtHeights.sort()

    all_red_taller = True
    all_blue_taller = True

    for red, blue in zip(redShirtHeights, blueShirtHeights):
        all_red_taller &= red > blue
        all_blue_taller &= blue > red

    return all_blue_taller or all_red_taller


if __name__ == "__main__":
    red_heights = list(map(int, input().rstrip().split(" ")))
    blue_heights = list(map(int, input().rstrip().split(" ")))

    print(classPhotos(red_heights, blue_heights))