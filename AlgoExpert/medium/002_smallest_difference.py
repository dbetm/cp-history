# solved
# tags: implementation, sorting, pointers


def smallestDifference(arrayOne, arrayTwo):
    """My solution:
    Time: O(R log R)
    Space: O(m + n)

    Where n is the length of arrayOne, m of arrayTwo and R the max of n and m. 
    """
    arrayOne.sort()
    arrayTwo.sort()

    n = len(arrayOne)
    m = len(arrayTwo)
    all_numbers = list()

    one_idx = 0
    two_idx = 0

    while one_idx < n or two_idx < m:
        if one_idx >= n:
            all_numbers.append((arrayTwo[two_idx], 2))
            two_idx += 1
        elif two_idx >= m:
            all_numbers.append((arrayOne[one_idx], 1))
            one_idx += 1
        else:
            if arrayOne[one_idx] > arrayTwo[two_idx]:
                all_numbers.append((arrayTwo[two_idx], 2))
                two_idx += 1
            else:
                all_numbers.append((arrayOne[one_idx], 1))
                one_idx += 1

    ans = [arrayOne[0], arrayTwo[-1]]
    diff = abs(arrayOne[0] - arrayTwo[-1])

    for x in range(0, len(all_numbers) - 1):
        if all_numbers[x][1] != all_numbers[x+1][1]:
            tmp_diff = abs(all_numbers[x][0] - all_numbers[x+1][0])

            if tmp_diff < diff:
                diff = tmp_diff
                
                if all_numbers[x][1] == 1:
                    ans = [all_numbers[x][0], all_numbers[x+1][0]]
                else:
                    ans = [all_numbers[x+1][0], all_numbers[x][0]]

                if diff == 0:
                    break

    return ans


def smallestDifference2(arrayOne, arrayTwo):
    arrayOne.sort()
    arrayTwo.sort()

    n = len(arrayOne)
    m = len(arrayTwo)

    one_idx = 0
    two_idx = 0
    ans = [arrayOne[0], arrayTwo[-1]]
    diff = abs(arrayOne[0] - arrayTwo[-1])

    while one_idx < n and two_idx < m:
        tmp_diff = abs(arrayOne[one_idx] - arrayTwo[two_idx])

        if tmp_diff < diff:
            diff = tmp_diff
            ans = [arrayOne[one_idx], arrayTwo[two_idx]]

            if diff == 0:
                break

        if arrayOne[one_idx] < arrayTwo[two_idx]:
            one_idx += 1
        else:
            two_idx += 1

    return ans


if __name__ == "__main__":
    arr1 = list(map(int, input().split()))
    arr2 = list(map(int, input().split()))

    print(smallestDifference(arr1, arr2))
    print(smallestDifference2(arr1, arr2))
