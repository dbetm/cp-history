# https://www.hackerrank.com/challenges/lisa-workbook/problem
# Tag(s): Implementation, maths


def workbook(n, k, arr):
    num_page = 0
    ans = 0

    for x in arr:
        pages_per_chap = x // k + int(x % k != 0)

        a = 1
        b = min(k, x)
        for page in range(num_page + 1, num_page + pages_per_chap + 1):
            if page >= a and page <= b:
                ans += 1

            a = min(a + k, x)
            b = min(b + k, x)

        num_page += pages_per_chap

    return ans



if __name__ == '__main__':
    n, k = list(map(int, input().split()))

    arr = list(map(int, input().split()))

    print(workbook(n, k, arr))
