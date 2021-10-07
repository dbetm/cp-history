# https://app.codesignal.com/interview-practice/task/pMvymcahZ8dY4g75q/description
# Tag(s): Arrays

def firstDuplicate(a):
    n = len(a)
    duplicated = [False]*n
    ans = -1

    for i in range(n):
        if(duplicated[a[i]-1]):
            ans = a[i]
            break
        duplicated[a[i]-1] = True

    return ans


if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))

    print(firstDuplicate(a))
