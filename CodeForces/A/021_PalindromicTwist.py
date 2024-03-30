# https://codeforces.com/problemset/problem/1027/A
# Implementation, strings

def is_palindrome(s):
    ans = True

    left = 0
    right = len(s) - 1

    while(left < right):
        if (s[left] == 'a' and s[right] == 'a') or (s[left] == 'z' and s[right] == 'z'):
            pass
        elif (s[left] == 'a' and s[right] == 'z') or (s[left] == 'z' and s[right] == 'a'):
            ans = False
            break
        elif (s[left] == 'a' and s[right] != 'c') or (s[right] == 'a' and s[left] != 'c'):
            ans = False
            break
        elif (s[left] == 'z' and s[right] != 'x') or (s[right] == 'z' and s[left] != 'x'):
            ans = False
            break
        else:
            possible = False

            if (ord(s[left]) + 1) == (ord(s[right]) + 1):
                possible = True
            elif (ord(s[left]) + 1) == (ord(s[right]) - 1):
                possible = True
            elif (ord(s[left]) - 1) == (ord(s[right]) + 1):
                possible = True
            elif (ord(s[left]) - 1) == (ord(s[right]) - 1):
                possible = True

            if not possible:
                ans = False
                break

        left += 1
        right -= 1

    return ans

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        n = int(input())
        s = input()

        ans = is_palindrome(s)

        if ans:
            print('YES')
        else:
            print('NO')
