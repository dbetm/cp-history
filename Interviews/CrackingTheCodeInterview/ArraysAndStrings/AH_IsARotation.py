
def is_a_rotation(str_1, str_2):
    if len(str_1) != len(str_2):
        return False

    ans = False
    n = len(str_1)
    for i in range(n):
        match = True
        for j in range(n):
            if str_1[j] != str_2[(j + i) % n]:
                match = False
                break
        if match:
            ans = True
            break

    return ans


def is_a_rotation_v2(str_1, str_2):
    if len(str_1) != len(str_2):
        return False

    str_x = str_1 + str_1

    return str_2 in str_x

if __name__ == '__main__':
    str_1 = input("Type first string: ")
    str_2 = input("Type second string: ")

    print(is_a_rotation(str_1, str_2))
    print(is_a_rotation_v2(str_1, str_2))
