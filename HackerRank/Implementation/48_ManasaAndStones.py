# https://www.hackerrank.com/challenges/manasa-and-stones/problem
# Tag(s): maths, implemenation

def compute_final_stones(n, a, b):
    stones = set()
    final_stone = a * (n-1)

    stones.add(final_stone)

    for i in range(n-1):
        final_stone = (final_stone - a) + b
        stones.add(final_stone)

    return list(sorted(stones))


if __name__ == '__main__':
    t = int(input())

    for i in range(t):
        n = int(input())
        a = int(input())
        b = int(input())

        ans = compute_final_stones(n, a, b)

        for x in ans:
            print(x, end=" ")
        print("")
