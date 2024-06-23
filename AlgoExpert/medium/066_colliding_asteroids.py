# solved
# tags: stack, data-structures, implementation


def collidingAsteroids(asteroids):
    """My solution
    Time: O(n)
    Space: O(n)
    """
    result = list() # works as a stack

    for asteroid in asteroids:
        if len(result) == 0:
            result.append(asteroid)
        elif result[-1] > 0 and asteroid < 0:
            while (
                len(result) > 0 
                and result[-1] > 0 and asteroid < 0 
                and abs(result[-1]) < abs(asteroid)
            ):
                result.pop()

            if len(result) == 0:
                result.append(asteroid)
            elif abs(result[-1]) == abs(asteroid):
                result.pop()
            elif result[-1] < 0:
                result.append(asteroid)
        else:
            result.append(asteroid)

        print(f"{asteroid=}")
        print(f"{result=}")
        print("-"*32)

    return result


if __name__ == "__main__":
    asteroids = list(map(int, input("").split(" ")))

    print(collidingAsteroids(asteroids))

