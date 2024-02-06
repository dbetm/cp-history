# solved
# tags: math, map, implementation


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


def missingNumbers2(nums):
    """Proposal
    Time: O(n)
    Space: O(1)

    The idea is to find the sum of the two missing numbers, after that we will know that one
    missing number will be less than the average of the two numbers and the another will be greater, so we will find the missing number for each half, subtracting the expected sum from the current sum.

    To find the sum of the missing numbers we can use Euler formula, for example:
    expected: 1,2,3,4,5
    current: 1,3,4

    expected sum: 5*6 / 2 = 15
    current sum: 8
    
    sum of missing numbers: 15 - 8 = 7

    the average: 7/2 = 3.5 (3)
    1) Iterate current, summing all numbers less than average: 1
    2) Calulate expected sum n=2, n(n+1)*0.5 = 3
    3) Find first missing number: 3-1 = 2

    4) Iterate current, summing up all numbers greater or equal than average: 3+4=7
    5) Calculate expected sum, n=5, 5*(6)*0.5 = 15, subtract another expected sum, 15-3=12
    6) Find second missing number: 12-7=5  
    """
    m = len(nums)
    n = m + 2
    ans = list()
    expected_sum = 0
    current_sum = 0

    if m == 0:
        return [1, 2]

    for num in nums:
        current_sum += num

    expected_sum = (n * (n+1)) // 2
    missing_sum = expected_sum - current_sum

    average = missing_sum // 2

    left_sum = 0
    right_sum = 0
    for idx in range(m):
        if nums[idx] <= average:
            left_sum += nums[idx]
        else:
            right_sum += nums[idx]

    n_left = average
    expected_left = (n_left * (n_left + 1)) // 2
    ans.append(expected_left - left_sum)

    expected_right = expected_sum - expected_left
    ans.append(expected_right - right_sum)

    return ans


if __name__ == "__main__":
    nums = list(map(int, input().split()))

    print(missingNumbers(nums))
    print(missingNumbers2(nums))
