# solved
# tags: strings, implementation


def longestPalindromicSubstring0(string):
    n = len(string)

    if n <= 1:
        return string

    max_len = 0
    idx_start = -1
    idx_end = -1
    # palindromes can have an even or odd number of chars
    left = -1
    right = -1

    for pos in range(1, n):
        # check when the palindrome can be of even number of chars
        has_init = False
        num_chars = 0

        if (pos + 1) < n and string[pos - 1] == string[pos + 1]:
            left = pos - 1
            right = pos + 1
            num_chars = 1
            has_init = True
        elif string[pos - 1] == string[pos]:
            left = pos - 1
            right = pos
            has_init = True
        elif (pos + 1) < n and string[pos + 1] == string[pos]:
            left = pos
            right = pos + 1

        if has_init:
            print(left, pos, right)

            while left >= 0 and right < n:
                if string[left] != string[right]:
                    if num_chars > max_len:
                        max_len = num_chars
                        idx_start = left + 1
                        idx_end = right - 1
                    break
                print(string[left], string[right])
                num_chars += 2

                left -= 1
                right += 1

            if left < 0 and num_chars > max_len:
                idx_start = 0
                idx_end = right - 1
                max_len = num_chars
            elif right >= n and num_chars > max_len:
                idx_start = left + 1
                idx_end = n - 1
                max_len = num_chars

        print("-"*12)

    print(f"{idx_start=}")

    return string[idx_start:idx_end+1]



def check_palindrome(string, left, right) -> bool:
    ans = True

    while left < right:
        #print(f"{string[left]=}", f"{string[right]=}")
        if string[left] != string[right]:
            ans = False
            break
        left += 1
        right -= 1

    return ans


def longestPalindromicSubstring(string):
    """My solution
    Time: O(n^2)
    Space: O(1)

    Where n is the number of character of string
    """
    n = len(string)

    if n <= 1:
        return string

    max_left = -1
    max_right = -1
    max_len = 0

    for idx in range(n):
        left = idx
        right = n-1

        print(f"{left=}", f"{right=}")

        while left < right:
            if check_palindrome(string, left, right):
                print("found", left, right)
                len_ = right - left + 1
                if len_ > max_len:
                    max_len = len_
                    max_left = left
                    max_right = right
                break
            print(f"{right=}")
            right -= 1

        print("-"*12)

    print(f"{max_left=}", f"{max_right=}")

    return string[max_left:max_right+1]


if __name__ == "__main__":
    string = input()

    print(longestPalindromicSubstring(string))
