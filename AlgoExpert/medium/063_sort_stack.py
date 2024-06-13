# solved
# tags: stack, data-structure, sorting


def sortStack(stack: list):
    """My solution
    Time: O(n^2)
    Space: O(n)
    """
    if len(stack) <= 1:
        return stack

    num = stack.pop()
    top = stack.pop()
    # print(f"{num=}, {top=}")

    if num < top:
        stack.append(num)
        sortStack(stack)

        if top < stack[-1]:
            tmp = stack.pop()
            stack.append(top)
            sortStack(stack)
            stack.append(tmp)
        else:
            stack.append(top) 
    else:
        stack.append(top)
        sortStack(stack)

        if num < stack[-1]:
            tmp = stack.pop()
            stack.append(num)
            sortStack(stack)
            stack.append(tmp)
        else:
            stack.append(num)

    return stack


def insert(stack: list, num):
    if len(stack) == 0 or num >= stack[-1]:
        stack.append(num)
        return

    top = stack.pop()

    insert(stack, num)

    stack.append(top)


def sortStack2(stack: list):
    """Proposal
    Time: O(n^2)
    Space: O(n)
    """
    if len(stack) == 0:
        return stack

    top = stack.pop()

    sortStack(stack)
    insert(stack, top)

    return stack


if __name__ == "__main__":
    stack = list(map(int, input().split()))

    print(sortStack2(stack))
