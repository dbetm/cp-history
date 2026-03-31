# https://www.hackerrank.com/challenges/the-time-in-words/problem
# tags: implementation, strings, modulo

NUM_TO_WORD = {
    1: "one",
    2: "two",
    3: "three",
    4: "four",
    5: "five",
    6: "six",
    7: "seven",
    8: "eight",
    9: "nine",
    10: "ten",
    11: "eleven",
    12: "twelve",
    13: "thirteen",
    14: "fourteen",
    16: "sixteen",
    17: "seventeen",
    18: "eighteen",
    19: "nineteen",
    20: "twenty",
}


def time_in_words(h: int, m: int) -> str:
    next_hour = max(1, (h + 1) % 13)

    if m == 0:
        return f"{NUM_TO_WORD[h]} o' clock"

    if m == 1:
        return f"one minute past {NUM_TO_WORD[h]}"

    if m == 15:
        return f"quarter past {NUM_TO_WORD[h]}"

    if m == 30:
        return f"half past {NUM_TO_WORD[h]}"

    if m == 45:
        return f"quarter to {NUM_TO_WORD[next_hour]}"

    if m == 59:
        return f"one minute to {NUM_TO_WORD[next_hour]}"

    if m <= 20:
        return f"{NUM_TO_WORD[m]} minutes past {NUM_TO_WORD[h]}"

    if m < 30:
        return f"{NUM_TO_WORD[20]} {NUM_TO_WORD[m % 20]} minutes past {NUM_TO_WORD[h]}"

    rem = 60 - m
    if m >= 40:
        return f"{NUM_TO_WORD[rem]} minutes to {NUM_TO_WORD[next_hour]}"

    return f"{NUM_TO_WORD[20]} {NUM_TO_WORD[rem % 20]} minutes to {NUM_TO_WORD[next_hour]}"




if __name__ == '__main__':

    hour = int(input().strip())
    minute = int(input().strip())


    print(time_in_words(hour, minute))