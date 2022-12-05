NUMBER_MAX_INT_BYTES = 64


def convert_int_to_str_bin(n: int) -> str:
    str_bin = ""

    while n:
        str_bin += str(n % 2)
        n //= 2

    header_zeros = max(0, NUMBER_MAX_INT_BYTES - len(str_bin))

    return "0"*header_zeros + str_bin[::-1]


def count_differences(num1: str, num2: str) -> int:
    assert len(num1) == len(num2)
    cont = 0
    # Alternative: It's possible to use XOR ane then count then 1's bits.
    for a_i, b_i in zip(num1, num2):
        if a_i != b_i:
            cont += 1

    return cont


if __name__ == '__main__':
    a, b = list(map(int, input().split(" ")))

    str_bin_a = convert_int_to_str_bin(a)
    str_bin_b = convert_int_to_str_bin(b)

    print(str_bin_a)
    print(str_bin_b)

    print(count_differences(str_bin_a, str_bin_b))
