# solved
# tags: data-structures, stack, math


def reversePolishNotation(tokens):
    """My solution
    Time: O(n)
    Space: O(n)
    """

    if len(tokens) == 1:
        return int(tokens[0])

    stack = list()
    result = -1

    for token in tokens:
        if token == "+":
            b = stack.pop()
            a = stack.pop()

            result = a + b
            stack.append(result)
        elif token == "-":
            b = stack.pop()
            a = stack.pop()

            result = a - b
            stack.append(result)
        elif token == "*":
            b = stack.pop()
            a = stack.pop()

            result = a * b
            stack.append(result)
        elif token == "/":
            b = stack.pop()
            a = stack.pop()

            result = int(a / b)

            stack.append(result)
        else:
            stack.append(int(token))

    return result


if __name__ == "__main__":
    tokens = list(input().split(" "))

    print(reversePolishNotation(tokens))
