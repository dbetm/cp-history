# solved
# Tag(s): implementation, strings


def code(string: str) -> str:
    ans = ""

    for c in string:
        ans += str(letter_map[ord(c) - 65])

    return ans



if __name__  == "__main__":
    t = int(input())

    for i in range(1, t+1):
        global letter_map
        letter_map = list(map(int, input().split(" ")))
        n = int(input())
        used_codes = set()
        has_collision = False

        for _ in range(n):
            string = input()

            if not has_collision:
                coded_string = code(string)

                if coded_string in used_codes:
                    has_collision = True
                else:
                    used_codes.add(coded_string)

        ans = "YES" if has_collision else "NO"
        print(f"Case #{i}: {ans}")

