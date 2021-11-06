#
# Tag(s):

# it's necessary figure out a formula
"""
r = n // 2
p = n - r
d = 8
if x is even:
    x -= 1
    x -= 2 + (r-1)*d
    x += 4 + (p-1)*d
else:

"""
def compute_final_pos(x, n):

    if n == 0:
        return x
    elif n <= 5:
        d = 1
        for _ in range(n):
            if x & 1: # right
                x += d
            else:
                x -= d
            d += 1

        return x


    r = (n-2) // 4 if not n & 1 else n // 4
    d = 8
    ans = x

    if x & 1: # odd
        ans += 1
    else: # even
        ans -= 1

    if n & 1:
        ans -= (r * (5 + (2 * n - 7))) // 2
        ans += (r * (9 + (2 * n - 3))) // 2
    else:
        ans += (r * (5 + (2 * n - 9))) // 2
        ans -= (r * (9 + (2 * n - 5))) // 2
        ans += n

    return ans


if __name__ == '__main__':
    t = int(input())

    for i in range(t):
        x, n = list(map(int, input().split()))
        print(compute_final_pos(x, n))
