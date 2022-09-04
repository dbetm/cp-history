
def int2bin(n: int):
    ans = ""

    while n:
        ans += str(n % 2)
        n //= 2

    return ans[::-1]


def dec2bin(x: float):
    """To print the decimal part, we can multiply by 2 and check
    if the 2*n is greater than or equal to one. This is essentially
    <<shifting>> the fractional sum.
    """
    ans = ""

    while x > 0:
        if len(ans) > 32:
            raise Exception()

        if x == 1:
            ans += "1"
            break

        r = x * 2
        print("x: ", x, "ans: ", ans, "r:", r)
        input()
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
        int_str = int2bin(int(inte))
        dec_str = dec2bin(float(f".{deci}"))
        # it's wrong the decimal part
        print(f"{int_str}.{dec_str}")
    except Exception as e:
        print("ERROR")
