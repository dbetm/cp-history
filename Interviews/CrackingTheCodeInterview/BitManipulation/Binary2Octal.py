


def binary_to_octal(bin_num: str) -> str:
    n = len(bin_num)

    reversed_bin_num = bin_num[::-1]
    resultado = ""

    for i in range(0, n, 3):
        dig = 0
        if reversed_bin_num[i+0] == "1":
            dig += 1
        if i+1 < n and reversed_bin_num[i+1] == "1":
            dig += 2
        if i+2 < n and reversed_bin_num[i+2] == "1":
            dig += 4

        resultado += str(dig)
    
    return resultado[::-1]




if __name__ == '__main__':
    cases = (
        "111", "111000", "1010001", "110000"
    )

    for case in cases:
        print(case, "=", binary_to_octal(bin_num=case))