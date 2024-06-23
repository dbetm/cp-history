#
# tags:

import time


def nextGreaterElement(array):
    # It's wrong
    n = len(array)

    if n == 0:
        return array

    output = [-1 for _ in range(n)]
    used_indices = set([i for i in range(n)])
    stack = list()
    idx = 0
    is_init = True

    while len(used_indices) > 0:
        num = array[idx]

        if len(stack) == 0 and is_init:
            stack.append((num, idx))
            is_init = False
        elif len(stack) == 0 and not is_init:
            break
        elif num > stack[-1][0]:
            while len(stack) > 0 and num > stack[-1][0]:
                top = stack.pop()
                if output[top[1]] == -1:
                    output[top[1]] = num
                    used_indices.remove(top[1])
            if len(stack) > 0 and stack[-1][1] == idx:
                used_indices.remove(stack[-1][1])
                stack.pop()
            else:
                stack.append((num, idx))
        elif num == stack[-1][0] and stack[-1][1] == idx:
            print("hello world", stack[-1][1], idx)
            used_indices.remove(stack[-1][1])
        else:
            stack.append((num, idx))

        print(f"{stack=}")
        print(f"{output=}")
        print(f"{used_indices=}")
        print("-"*23)

        time.sleep(0.5)

        idx = (idx + 1) % n

    return output


def nextGreaterElement2(array):
    """Proposal
    Time: O(n)
    Space: O(n)
    """
    n = len(array)
    stack = list()
    output = [-1 for _ in range(n)]

    for i in range(n*2):
        idx = i % n
        num = array[idx]

        if i == 0:
            stack.append(idx)
        elif num > array[stack[-1]]:
            while len(stack) > 0 and num > array[stack[-1]]:
                output[stack[-1]] = num
                stack.pop()
            stack.append(idx)
        else:
            stack.append(idx)

    return output



if __name__ == "__main__":
    arr = list(map(int, input().split()))

    print(nextGreaterElement2(arr))
