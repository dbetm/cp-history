# https://www.hackerrank.com/challenges/funny-string/problem
# Tag(s): strings

def is_funny(s):
    n = len(s)
    ans = 'Funny'

    j = n - 1
    for i in range(n-1):
        if abs(ord(s[i])-ord(s[i+1])) != abs(ord(s[j])-ord(s[j-1])):
            ans = 'Not Funny'

    return ans


if __name__ == '__main__':
    q = int(input())

    for i in range(q):
        s = input()
        print(is_funny(s))
