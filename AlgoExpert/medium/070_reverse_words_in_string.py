#
# tags:


def split(string) -> list:
    ans = list()
    substr = ""

    for c in string:
        if substr == "":
            substr += c
        elif c == " " and substr[-1] == " ":
            substr += c
        elif c == " " and substr[-1] != " ":
            ans.append(substr)
            substr = c
        elif c != " " and substr[-1] != " ":
            substr += c
        elif c != " " and substr[-1] == " ":
            ans.append(substr)
            substr = c
        else:
            print(f"{substr=}", f"{ans=}")
            raise Exception("something wrong")

    ans.append(substr)

    return ans


def reverseWordsInString(string):
    """My solution
    Time: O(n)
    Space: O(n)

    Where n is the number of invidivual characters in the given string.
    """
    splitted = split(string)
    reversed_splitted = list()

    while len(splitted) > 0:
        reversed_splitted.append(splitted.pop())

    return "".join(reversed_splitted)


if __name__ == "__main__":
    string = input("")

    print(reverseWordsInString(string))
