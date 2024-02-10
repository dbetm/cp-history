# solved
# tags: implementation, pointer


def sweetAndSavory(dishes, target):
    """My solution:
    Time: O(n)
    Space: O(1)
    """
    dishes.sort()
    ans = [0, 0]

    if len(dishes) == 0 or dishes[0] > 0 or dishes[-1] < 0:
        return ans

    res = dishes[-1] + dishes[0]
    delta = abs(target - res) if res <= target else 2**31
    ans = [dishes[0], dishes[-1]] if res <= target else [0, 0]
    sweet_idx = 0
    savory_idx = len(dishes) - 1

    while dishes[sweet_idx] < 0 and dishes[savory_idx] > 0:
        res = dishes[savory_idx] + dishes[sweet_idx]

        if res > target:
            savory_idx -= 1
            continue

        if res == target:
            ans[0] = dishes[sweet_idx]
            ans[1] = dishes[savory_idx]
            delta = abs(target - res)
            break

        tmp_delta = abs(target - res)
        if tmp_delta < delta:
            delta = tmp_delta 
            ans[0] = dishes[sweet_idx]
            ans[1] = dishes[savory_idx]

        sweet_idx += 1

    print("delta", delta)

    return ans


if __name__ == "__main__":
    dishes = list(map(int, input().split()))
    target = int(input())

    print(sweetAndSavory(dishes, target))
