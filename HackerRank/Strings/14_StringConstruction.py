#
# Tag(s):

"""
def compute_cost(s):
    n = len(s)
    cost = 0

    all_subs = set()
    p = ""

    for i in range(n):
        x = s[i]
        k = i

        if x in all_subs:
            # hacer append de todas las subcadenas que se pueden usar sin costo
            while True:
                if (k + 1) < n and (x + s[k + 1]) in all_subs:
                    k += 1
                    x += s[k]
                else:
                    break
        else:
            cost += 1

        if not x in all_subs:
            all_subs.add(x)

        p += x

        if k >= n:
            break

        m = len(p)
        for j in range(m-1, -1, -1):
            if not p[j:] in all_subs:
                all_subs.add(p[j:])

    return cost
"""

"""
def compute_cost(s: str) -> int:
    n = len(s)

    p = s[0]
    cost = 1

    for i in range(1, n):
        has_cost = True
        for j in range(n, i, -1):
            if s[i:j] in p:
                p += s[i:j]
                i = j
                has_cost = False
                break

        if has_cost:
            p += s[i]
            cost += 1

    return cost
"""


"""Solution:
It doesn't matter if the resting substring in s is large or not, there's no cost, so
the problem is reduced to count the unique characters, because always we can use a single
char to copy from s to p.
"""

def compute_cost(s: str) -> int:
    return len(set(s))


if __name__ == '__main__':
    n = int(input())

    for i in range(n):
        s = input()
        print(compute_cost(s))
