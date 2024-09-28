#
# tags:


def compute_anagrams(s: str) -> list:
    substrings = list()
    positions = list()

    n = len(s)

    for i in range(n):
        current_position = list()
        for j in range(i, n):
            current_substr = s[i:j+1]
            current_position.append(j)

            substrings.append(current_substr)
            positions.append(current_position)


if __name__ == "__main__":
    q = int(input())

    for i in range(q):
        s = input("")

        print(compute_anagrams(s))
    

