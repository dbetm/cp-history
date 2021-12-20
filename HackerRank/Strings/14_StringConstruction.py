#
# Tag(s):

def compute_cost(s):
    n = len(s)
    cost = 0

    all_subs = set()
    p = ''

    for i in range(n):
        x = s[i]
        if x in all_subs:
            while True:
                if (i + 1) < n and (x + s[i + 1]) in all_subs:
                    i += 1
                    x += s[i]
                else:
                    break
        else:
            cost += 1

        if not x in all_subs:
            all_subs.add(x)

        p += x
        # print("p", p, "x", x)
        m = len(p)
        for j in range(m-1, -1, -1):
            if not p[j:] in all_subs:
                all_subs.add(p[j:])

    return cost


if __name__ == '__main__':
    n = int(input())

    for i in range(n):
        s = input()
        print(compute_cost(s))
