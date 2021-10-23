# WA
# Tag(s):
def findLongestSubarrayBySum(s, arr):
    acc = dict()
    # compute accumulated sum
    sum_acc = 0
    for i, x in enumerate(arr):
        sum_acc += x
        acc[sum_acc] = i
    left = -1
    right = -1
    #sorted_acc = sorted(acc)
    # print(sorted_acc)

    for sum_acc, original_index in acc.items():
        # original_index = acc[sum_acc]
        target = s + sum_acc - arr[original_index]
        if target in acc:
            left = original_index
            right = acc[target]
            break


    if left != -1:
        ans = [left + 1, right + 1]
    else:
        ans = [-1]

    return ans

if __name__ == '__main__':
    s = int(input())
    arr = list(map(int, input().split()))

    print(findLongestSubarrayBySum(s, arr))
