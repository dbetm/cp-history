# solved
# tags: stack, implementation, data-structures


def sunsetViews(buildings, direction):
    """My solution
    Time: O(n)
    Space: O(n)
    """
    ans = list()
    current_max = 0

    if direction == "WEST":
        for idx, height in enumerate(buildings):
            if height > current_max:
                current_max = height
                ans.append(idx)
    else:
        n = len(buildings)
        for idx, height in enumerate(reversed(buildings)):
            if height > current_max:
                current_max = height
                ans.append(n - idx - 1)
        ans.reverse()

    return ans



if __name__ == "__main__":
    buildings = list(map(int, input().split()))
    direction = input()

    print(sunsetViews(buildings, direction))
