from typing import Tuple

"""Given an integer, print the next smallest and next largest number
that have the same number of 1 bits in their binary representation.
"""

""" Approach
Prior observations:
- If we turn on a 0, we need to turn off a 1. i.e 0->1 and 1->0. To keep the
same number of 1 bits.
- I we 0->1 at bit i and turn off a 1 at bit j, the number changes by 2^i - 2^j
    Example: 10100 (20)
    i = 3 and j = 2 | 2^3 = 8 | 2^2 = 4 | 2^i - 2^j = 4
             11000 (24)
- Notice that if we want to get a bigger number with the same number of 1s and
    0s, i must be bigger than j.


Solution:
    1) Get the next greatest number
        - Traverse from rigth to left. Once we've passed a 1, turn on the next 0.
        We've now increased the number by 2^i. Example: xxxx011100 becomes
        xxxx111100.
        - Turn off the one that's just to the right side of that. We're now bigger
        by 2^i-2^(i-1). Example: xxxx111100 becomes xxxx101100.
        - Make the number as small as possible by rearranging all the 1s to be as
        far right as possible. Example: xxxx101100 becomes xxxx100011.
    2) Get the next smallest number
        - Traverse from right to left. Once we've passed a zero, turn off the next
        1. Example: xxxx100011 becomes xxxx000011.
        - Turn on the 0 that is directly to the right. Example: xxxx000011 becomes
        xxxx010011.
        - Make the number as big as possible by shifting all the ones as far to the
        left as possible. Example: xxxx010011 becomes xxxx011100.
"""
def convert_int_to_str_bin(n: int) -> str:
    ans = ""

    while n:
        ans += str(n % 2)
        n //= 2

    return ans[::-1]


def convert_str_binary_to_int(str_bin: str) -> int:
    max_power = len(str_bin) - 1
    ans = int()

    for bit in str_bin:
        ans += 2**max_power * (1 if bit == "1" else 0)
        max_power -= 1

    return ans


def turn_on_next_zero_after_one(str_bin: str) -> Tuple[str, int]:
    len_size = len(str_bin)
    new_str = ""
    has_found_one = False
    has_to_add_digit = True
    ptr = -1

    for i in range(len_size - 1, -1, -1):
        if str_bin[i] == "0" and has_found_one:
            new_str += "1"
            new_str += str_bin[:i][::-1]
            has_to_add_digit = False
            ptr += 1
            break

        if str_bin[i] == "1" and not has_found_one:
            has_found_one = True

        new_str += str_bin[i]
        ptr += 1

    if has_to_add_digit:
        new_str = ("0" * len_size) + "1"
        ptr += 1

    return (new_str[::-1], ptr)


def is_power_of_two(str_bin: str) -> bool:
    x = 0

    while x < len(str_bin):
        if str_bin[x] != "0":
            break
        x += 1

    trail_elements = set(str_bin[x+1:])

    return (
        str_bin[x] == "1"
        and (trail_elements == {"0"} or trail_elements == set())
    )


def turn_x_given_bit_pos(str_bin: str, bit_pos: int, on: bool) -> str:
    n = len(str_bin)
    idx = n - bit_pos - 1
    bit = 1 if on else 0

    return str_bin[0:idx] + str(bit) + str_bin[idx+1:]


def small_number(str_bin: str, bit_pos: int) -> str:
    """Make the number as small as possible by rearranging all the 1s to be 
    as far right as possible, considering only the bits after the given bit_pos. 
    Example: 101100 becomes 100011.
    """
    number_trail_zeros = 0
    n = len(str_bin)
    idx = n - bit_pos - 1

    for i in range(n-1, -1, -1):
        if str_bin[i] == "1":
            break

        number_trail_zeros += 1

    smaller_number = str_bin[0:idx+1]
    smaller_number += "0"*number_trail_zeros
    smaller_number += str_bin[idx+1:n-number_trail_zeros]

    return smaller_number


def big_number(str_bin: str, bit_pos: int) -> str:
    """Make the number as big as possible by shifting all the ones as far to the 
    left as possible, considering only the bits after the given bit_pos.
    Example: 010011 becomes 011100.
    """
    number_head_zeros = 0
    n = len(str_bin)
    idx = n - bit_pos - 1

    for i in range(idx+1, n):
        if str_bin[i] == "1":
            break
        number_head_zeros += 1

    bigger_number = str_bin[0:idx+1]
    bigger_number += str_bin[idx+1+number_head_zeros:n]
    bigger_number += "0"*number_head_zeros

    return bigger_number


def turn_off_next_one_after_zero(str_bin) -> Tuple[str, int]:
    n = len(str_bin)
    new_str = ""
    has_found_zero = False
    ptr = -1

    for i in range(n - 1, -1, -1):
        if str_bin[i] == "1" and has_found_zero:
            new_str += "0"
            new_str += str_bin[:i][::-1]
            ptr += 1
            break

        if str_bin[i] == "0" and not has_found_zero:
            has_found_zero = True

        new_str += str_bin[i]
        ptr += 1

    return (new_str[::-1], ptr)


def find_next_greatest(str_binary: str) -> int:
    if is_power_of_two(str_binary):
        return convert_str_binary_to_int(str_binary) * 2

    greater_by_i, idx = turn_on_next_zero_after_one(str_binary)

    if len(greater_by_i) == len(str_binary):
        # turn off bit idx-1
        greater_by_i_1 = turn_x_given_bit_pos(greater_by_i, idx-1, on=False)
        small_as_possible = small_number(greater_by_i_1, idx)
    else:
        number_1_bits = len(str_binary)
        small_as_possible = "10" + "1"*(number_1_bits - 1)

    return convert_str_binary_to_int(small_as_possible)


def find_next_smallest(str_binary: str) -> int:
    if is_power_of_two(str_binary):
        return convert_str_binary_to_int(str_binary) // 2

    smaller_by_i, idx = turn_off_next_one_after_zero(str_binary)
    # turn on bit idx-1
    smaller_by_i_1 = turn_x_given_bit_pos(smaller_by_i, idx-1, on=True)
    big_as_possible = big_number(smaller_by_i_1, idx-1)

    return convert_str_binary_to_int(big_as_possible)


if __name__ == '__main__':
    n = int(input())

    str_binary = convert_int_to_str_bin(n)

    next_largest_number = find_next_greatest(str_binary)
    next_smallest_number = find_next_smallest(str_binary)

    print(f"{next_smallest_number} {n} {next_largest_number}")
