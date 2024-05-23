# solved
# tags: strings, recursion

keyboard = {
    1: ["1"],
    2: ["a", "b", "c"],
    3: ["d", "e", "f"],
    4: ["g", "h", "i"],
    5: ["j", "k", "l"],
    6: ["m", "n", "o"],
    7: ["p", "q", "r", "s"],
    8: ["t", "u", "v"],
    9: ["w", "x", "y", "z"],
    0: ["0"]
}


def compute(mnemonics: list, mnemonic: str, dx: int, phone_number: str):
    """My proposal
    Time: O(c(phone_number))
    Space: O(n*c(phone_number))

    Where c() is the cardinality, such as the number elements associated for each digit is multiplied.
    Where n is the number of digits in phone_number.

    Suggested optimal complexity

    Time: O(4^n * n)
    Space: O(4^n * n)

    4^n is because in the worst case, we have 4 possibilites for each digit and this could be the case for n digits.
    """
    n = len(phone_number)

    if dx == n:
        mnemonics.append(mnemonic)
        return

    for ps in keyboard[int(phone_number[dx])]:
        mnemonic += ps
        compute(mnemonics, mnemonic, dx+1, phone_number)
        mnemonic = mnemonic[:-1]


def phoneNumberMnemonics(phoneNumber):
    mnemonics = list()

    compute(mnemonics, "", 0, phoneNumber)

    return mnemonics



if __name__ == "__main__":
    phone_number = input()

    from pprint import pprint

    mnemonics = phoneNumberMnemonics(phone_number)
    pprint(mnemonics)
