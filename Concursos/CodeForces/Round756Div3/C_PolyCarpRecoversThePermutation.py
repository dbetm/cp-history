# Not sent
# Tag(s):
def check_permutation(n, p, a):
    left, right = n // 2, n // 2
    i = 0
    j = n - 1

    while i <= j:
        if p[i] < p[j]:
            if p[i] != a[left]:
                return False
            if left == right:
                right += 1
            left -= 1
            i += 1
        else:
            if p[j] != a[right]:
                return False
            if left == right:
                left -= 1
            right += 1
            j -= 1

    return True

def generate_permutation(n, arr, start_right=True):
    p = [0] * n
    left, right = n // 2, n // 2
    i = 0
    j = n - 1

    r = start_right
    while i <= j:
        if r:
            r = False

            if right >= n:
                break

            p[right] = arr[j]

            j -= 1

            if left == right:
                left -= 1
            right += 1
        else:
            r = True
            p[left] = arr[i]
            i += 1

            if left == right:
                right += 1
            left -= 1

    return p

def compute(n, arr):
    p_1 = generate_permutation(n, arr, True)
    print(p_1)
    p_2 = generate_permutation(n, arr, False)

    if check_permutation(n, p_1, arr):
        return p_1
    elif check_permutation(n, p_2, arr):
        return p_2

    return -1


if __name__ == '__main__':
    t = int(input())

    for i in range(t):
        n = int(input())
        arr = list(map(int, input().split()))

        ans = compute(n, arr)

        if ans == -1:
            print(ans)
        else:
            for x in ans:
                print(x, end=' ')
            print('')
