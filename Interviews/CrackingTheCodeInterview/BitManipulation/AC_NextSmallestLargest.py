"""Given an integer, print the next smallest and next largest number
that have the same number of 1 bits in their binary representation.
"""

""" Approach
Brute force: Given n as the input integer, then iterate n+k and n-t, and for
every n+i | n-j check if the number of bits it's the same. O(max(k, t)).
max(k, t) < 2*n
"""
def count_bits(n: int) -> int:
    count = 0

    while n:
        count += n % 2
        n //= 2

    return count


def find_next_blabla_est(n: int, delta: int = 1) -> int:
    orig_n = n
    expected_num_bits = count_bits(n)

    if expected_num_bits == 1:
        if delta == 1:
            return n << 1
        return n >> 1

    n += delta

    while expected_num_bits != count_bits(n):
        n += delta

        if n == 0:
            return orig_n

    return n


if __name__ == '__main__':
    n = int(input())

    next_smallest_number = find_next_blabla_est(n, -1)
    next_largest_number = find_next_blabla_est(n, 1)

    print(f"{next_smallest_number} {n} {next_largest_number}")
