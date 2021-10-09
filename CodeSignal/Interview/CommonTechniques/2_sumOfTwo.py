# https://app.codesignal.com/interview-practice/task/Hm98RnqK9Be575yoj/description
# Tag(s): pointers

def sumOfTwo(a, b, v):
    a.sort()
    b.sort(reverse=True)

    i = 0
    a_n = len(a)
    j = 0
    b_n = len(b)
    ans = False

    while i < a_n and j < b_n:
        total = a[i] + b[j]
        if total == v:
            ans = True
            break
        elif total > v:
            j += 1
        else:
            i += 1

    return ans

if __name__ == '__main__':
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    v = int(input())

    print(sumOfTwo(a, b, v))
