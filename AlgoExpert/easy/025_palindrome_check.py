# solved
# tags: implementation, strings, pointers


def isPalindrome(string):
    """My solution:
    Time: O(n)
    Space: O(1)
    """
    left = 0
    right = len(string) - 1
    is_palindrome = True

    while left < right:
        if string[left] != string[right]:
            is_palindrome = False
            break

        left += 1
        right -= 1

    return is_palindrome

if __name__ == "__main__":
    string = input()
    

    print(isPalindrome(string))
