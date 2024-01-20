import ast

# solved
# tags: implementation, recursion


def solve(item, nested_level):
    """My solution
    Time: O(n)
    Space: O(d)

    Where n is the number of elements in the array and d is the depth of 
    the special array.
    """
    if isinstance(item, int):
        return item

    nested_level += 1
    res = 0

    for x in item:
        res += solve(x, nested_level)

    return max(1, nested_level) * res


def productSum(array):
    return solve(array, 0)


if __name__ == '__main__':
    arr_str = input("")

    array = ast.literal_eval(arr_str)

    print(array)

    print(productSum(array))

