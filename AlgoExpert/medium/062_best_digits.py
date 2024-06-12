# solved
# tags: implementation, stack, data-structures


def bestDigits(number, numDigits):
    """Proposal
    Time: O(n)
    Space: O(n)
    """
    if numDigits == 0:
        return number

    stack = list()

    for num_str in number:
        num = int(num_str)

        if numDigits > 0:
            while len(stack) > 0 and numDigits > 0 and num > stack[-1]:
                stack.pop()
                numDigits -= 1

        stack.append(num)

    print(f"{stack=}")
    ans = stack[:(len(number) - numDigits)]

    return "".join(map(str, ans))


if __name__ == "__main__":
    number = input()
    num_digits = int(input())

    print(bestDigits(number, num_digits))
