#
# tags:


def missingNumbers(nums):
    """My solution:
    Time: O(n)
    Space: O(n)
    """
    m = len(nums)
    all_nums = [0 for _ in range(m + 3)]

    for num in nums:
        all_nums[num] = num
    
    missing_numbers = list()

    n = len(all_nums)

    for i in range(1, n):
        if all_nums[i] == 0:
            missing_numbers.append(i)

        if len(missing_numbers) == 2:
            break

    return missing_numbers


if __name__ == "__main__":
    nums = list(map(int, input().split()))

    print(missingNumbers(nums))
