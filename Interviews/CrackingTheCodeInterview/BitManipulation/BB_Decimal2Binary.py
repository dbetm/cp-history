
from math import isclose


def int_2_bin(n: int):
    ans = ""

    while n:
        ans += str(n % 2)
        n //= 2

    return ans[::-1]


def dec_2_bin(x: float):
    """ How to convert the fractional part of a decimal number to a binary 
    representation? 
    A decimal number like this: 3.72 is = 3 + 7*(1/10^1) + 2*(1/10^2)
    We need to check when any decimal part is 2-power or more, so we can
    multiply by 2 the decimal part in an iterative way and when the result has
    an integer part >= 1 then, we can append '1' to the ans.

    Only fractions with a denominator which is a power of two can be finitely represented in a binary form
    """
    ans = ""

    while x > 0:
        if len(ans) > 32:
            raise Exception()

        # base case, 1 is power of two
        if isclose(x, 1.0):
            ans += "1"
            break

        r = x * 2
        print("x: ", x, "ans: ", ans, "r:", r)

        if r >= 1:
            ans += "1"
            x = r - 1
        else:
            ans += "0"
            x = r

    return ans


if __name__ == '__main__':
    number = input()

    try:
        inte, deci = number.split(".")
        int_str = int_2_bin(int(inte))
        dec_str = dec_2_bin(float(f".{deci}"))
        # it's wrong the decimal part
        print(f"{int_str}.{dec_str}")
    except Exception as e:
        print("ERROR")
