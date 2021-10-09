# https://app.codesignal.com/interview-practice/task/CfknJzPmdbstXhsoJ/description?
# Tag(s): arrays

def containsDuplicates(a):
    a.sort()
    n = len(a)

    for i in range(n-1):
        if a[i] == a[i+1]:
            return True

    return False


if __name__ == '__main__':
    a = list(map(int, input().split()))

    print(containsDuplicates(a))
