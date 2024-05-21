# solved
# tags: implementation, math, bitwise


def powerset(arr: list):
    """My solution
    Time: O(n*2^n)
    Space: O(n*2^n)
    """
    n = len(arr)
    ans = list()

    for x in range(0, 2**n):
        new_set = list()
        for j in range(0, n):
            if 2**j & x:
                new_set.append(arr[j])
        
        ans.append(new_set)

    return ans


if __name__ == "__main__":
    arr = list(map(int, input().split()))

    ans = powerset(arr)

    from pprint import pprint

    pprint(ans)
