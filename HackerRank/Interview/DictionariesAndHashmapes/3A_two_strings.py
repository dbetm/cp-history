# https://www.hackerrank.com/challenges/two-strings
# tags: strings, sets


def has_common_substrings(s1: str, s2: str) -> bool:
    """My solution
    Time: O(max(len(s1), len(s2)))
    Space: O(1) # the max lenght of unique_chars_s1 must be 26
    """
    unique_chars_s1 = set(s1)
    ans = False

    for c in s2:
        if c in unique_chars_s1:
            ans = True
            break

    return ans


if __name__ == "__main__":
    p = int(input(""))

    for _ in range(p):
        s1 = input("")
        s2 = input("")

        print("YES" if has_common_substrings(s1, s2) else "NO")

