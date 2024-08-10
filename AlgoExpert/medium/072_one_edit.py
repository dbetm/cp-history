# solved
# tags: strings, implementation


def oneEdit(stringOne, stringTwo):
    """My solution
    Time: O(min(n, m))
    Space: O(1)
    """
    n = len(stringOne)
    m = len(stringTwo)

    if abs(n - m) > 1:
        return False
    
    if n == m:
        num_diffs = 0
        for a, b in zip(stringOne, stringTwo):
            if a != b and num_diffs > 0:
                return False
            elif a != b:
                num_diffs = 1
    else:
        # try to add element
        i, j = 0, 0
        added = False

        while i < n and j < m:
            if stringOne[i] != stringTwo[j] and not added:
                if n < m:
                    j += 1
                else:
                    i += 1

                added = True
                continue
            elif stringOne[i] != stringTwo[j]:
                return False

            i += 1
            j += 1

    return True


if __name__ == "__main__":
    str1 = input("")
    str2 = input("")

    print(oneEdit(str1, str2))
