# https://app.codesignal.com/interview-practice/task/njfXsvjRthFKmMwLC/description
# Tag(s): Hash tables, implementation

def containsCloseNums(nums, k):
    x = dict()
    ans = False

    for i in range(len(nums)):
        if nums[i] in x:
            ans = (i - x[nums[i]]) <= k
            if ans:
                break

        x[nums[i]] = i


    return ans

if __name__ == '__main__':
    nums = list(map(int, input().split()))
    k = int(input())

    print(containsCloseNums(nums, k))
