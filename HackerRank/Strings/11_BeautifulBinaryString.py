# https://www.hackerrank.com/challenges/beautiful-binary-string/problem
# Tag(s): strings
def compute_cost(b, n):
    ans = 0

    if n < 3:
        return ans

    patt = '010'
    i = 0

    while (i + 2) < n:
        cont = 0
        while patt == b[i:i+3]:
            i += 2
            cont += 1

        ans += cont // 2

        if cont & 1:
            ans += 1

        i += 1

    return ans



if __name__ == '__main__':
    n = int(input())
    b = input()

    print(compute_cost(b, n))
