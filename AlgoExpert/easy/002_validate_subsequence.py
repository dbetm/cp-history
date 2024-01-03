# solved
# tags: implementation, arrays


def isValidSubsequence(array, sequence):
    """My solution:
    Time: O(max(m, n))
    Memory: O(1)
    """
    n = len(array)
    i = 0

    for j, x in enumerate(sequence):
        was_found = False

        while i < n:
            if array[i] == x:
                was_found = True
                i += 1
                break
            i += 1  

        if not was_found:
            return False

    return True



if __name__ == "__main__":
    array = list(map(int, input().rstrip().split(" ")))
    sequence = list(map(int, input().rstrip().split(" ")))

    print(isValidSubsequence(array, sequence))