# solved
# tags: maths, implementation, recursion


def compute_factorial(n: int) -> int:
    cont = 1
    res = 1

    while cont <= n:
        res *= cont
        cont += 1

    return res


def getPermutations(array):
    """My solution
    It's wrong
    Time: O(n!)
    Space: O(n!*n)
    """
    ans = list()
    n = len(array)

    if n == 0:
        return array
    if n == 1:
        return [array]

    number_permutations = compute_factorial(n)
    i, j = 0, 1

    for _ in range(number_permutations):
        array[i], array[j] = array[j], array[i]
        ans.append(array.copy())

        i += 1
        j += 1

        i = i % n
        j = j % n

    return ans


def permutation_helper(i: int, array: list, permutations: list):
    n  = len(array)

    if i == (n-1):
        permutations.append(array[:])
    else:
        for j in range(i, n):
            swap(array, i, j)
            permutation_helper(i+1, array, permutations)
            # swap back
            swap(array, i, j)


def swap(array, i, j):
    array[i], array[j] = array[j], array[i]


def getPermutations2(array):
    """Proposal
    Time: O(n!*n)
    Space: O(n!*n)

    Example: [1, 2]
    --- call permutation_helper #1; i = 0, arr = [1,2], permutations=[]
        for j in range(0, 3):
            -- j = 0
                swap(0, 0) -> [1,2]
                permutation_helper #2 (1, [1,2], [])
                swap(0, 0) -> [1,2]
            -- j = 1
                swap(0, 1) -> [2,1]
                permutation_helper #3 (1, [2,1], [[1, 2]])
                swap(0, 1) -> [1,2]
    --- call permutation_helper #2; i = 1, arr = [1,2], permutations=[]
        add [1,2] to permutations because i == (2-1) -> permutations=[[1, 2]]
    --- call permutation_helper #3; i = 1, arr = [2,1], permutations=[[1, 2]]
        add [2,1] to permutations because i == (2-1) -> permutations=[[1, 2], [2, 1]]
    """
    permutations = list()

    permutation_helper(0, array, permutations)

    return permutations


if __name__ == "__main__":
    arr = list(map(int, input().split()))

    ans = getPermutations2(arr)
    print(len(ans))
    print(ans)
    
