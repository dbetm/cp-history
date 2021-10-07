# https://app.codesignal.com/interview-practice/task/uX5iLwhc6L5ckSyNC
# Tag(s): Arrays

def firstNotRepeatingCharacter(s):
    conts = [0]*26

    n = len(s)

    for i in range(n):
        conts[ord(s[i])-97] += 1

    ans = '_'
    for i in range(n):
        if(conts[ord(s[i])-97] == 1):
            ans = s[i]
            break

    return ans

if __name__ == '__main__':
    str = input()

    print(firstNotRepeatingCharacter(str))
