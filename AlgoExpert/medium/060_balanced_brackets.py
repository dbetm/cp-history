# solved
# tags: stack, strings, data-structures


BRACKETS = {
    ")": "(",
    "]": "[",
    "}": "{",
}


def balancedBrackets(string):
    """My solution
    Time: O(n)
    Space: O(n)
    """
    stack = list()
    opening_bracket = set(BRACKETS.values())

    for c in string:
        if c in opening_bracket:
            stack.append(c)
        else:
            if c not in BRACKETS.keys():
                continue
            if len(stack) > 0 and BRACKETS[c] == stack[-1]:
                stack.pop()
            else:
                return False

    return len(stack) == 0


if __name__ == "__main__":
    string = input()

    print(balancedBrackets(string))
