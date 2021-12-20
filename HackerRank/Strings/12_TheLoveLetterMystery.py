# https://www.hackerrank.com/challenges/the-love-letter-mystery/problem
# Tag(s): strings

def transform(s):
    l, r = 0, len(s)-1

    ans = 0

    while l < r:
        if s[l] != s[r]:
            ans += abs(ord(s[l])-ord(s[r]))

        l += 1
        r -= 1

    return ans

if __name__ == '__main__':
    q = int(input())

    for i in range(q):
        s = input()
        print(transform(s))
