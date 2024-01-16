# solved
# tags: implementation, pointers


def tandemBicycle(redShirtSpeeds, blueShirtSpeeds, fastest):
    """My solution
    Time: O(n log(n))
    Space: O(1)
    """
    redShirtSpeeds.sort()
    blueShirtSpeeds.sort()
    n = len(redShirtSpeeds)

    total_speed = 0

    if fastest:
        for i in range(0, n):
            total_speed += max(redShirtSpeeds[i], blueShirtSpeeds[n-i-1])
    else:
        for i in range(0, n):
            total_speed += max(redShirtSpeeds[i], blueShirtSpeeds[i])

    return total_speed



if __name__ == "__main__":
    red_speed = list(map(int, input().rstrip().split(" ")))
    blue_speeds = list(map(int, input().rstrip().split(" ")))

    fastest = input() == "true"

    print(tandemBicycle(red_speed, blue_speeds, fastest))