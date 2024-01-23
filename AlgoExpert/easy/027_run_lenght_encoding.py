# solved
# tags: strings, implementation


def runLengthEncoding(string):
    """My solution:
    Time: O(n)
    Space: O(n)
    """
    encoded_string = ""
    n = len(string)
    LIMIT_LENGHT = 9
    idx = 0

    while idx < n:
        char = string[idx]
        cont = 1
        idx += 1

        while idx < n and char == string[idx] and cont < LIMIT_LENGHT:
            cont += 1
            idx += 1

        encoded_string += f"{cont}{char}"

    return encoded_string


if __name__ == "__main__":
    string = input()

    print(runLengthEncoding(string))
