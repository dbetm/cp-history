from typing import Callable, Iterable

from AC_Opt_NextSmallestLargest import (
    big_number,
    convert_int_to_str_bin,
    convert_str_binary_to_int,
    is_power_of_two,
    small_number,
    turn_x_given_bit_pos,
    turn_off_next_one_after_zero,
    turn_on_next_zero_after_one,
)


def evaluate(in_out: list, fn: Callable):
    assert isinstance(fn, Callable)
    print(">>", fn.__name__, "<<", f"Cases: {len(in_out)}")
    has_errors = False

    for input_, expected in in_out:
        if isinstance(input_, Iterable) and not isinstance(input_, str):
            output = fn(*input_)
        else:
            output = fn(input_)

        try:
            assert output == expected
        except AssertionError:
            print("error!! Got:", output, "Expected:", expected, "Input:", input_)
            has_errors = True

    if not has_errors:
        print("Done 100%!")


tests = (
    (
        [(1, "1"), (9, "1001"), (13, "1101")],
        convert_int_to_str_bin
    ),
    (
        [("1", 1), ("1001", 9), ("1101", 13)],
        convert_str_binary_to_int
    ),
    (
        [
            ("011100", ("111100", 5)),
            ("100011100", ("100111100", 5)),
            ("1101", ("1111", 1)),
            ("111", ("1000", 3))
        ],
        turn_on_next_zero_after_one
    ),
    (
        [
            ("11100", False),
            ("100011100", False),
            ("1", True),
            ("100", True),
        ],
        is_power_of_two
    ),
    (
        [
            (("111100", 4, False), "101100"),
            (("100111100", 4, False), "100101100"),
            (("1111", 0, False), "1110"),
            (("1100", 2, False), "1000"),
            (("111100", 0, True), "111101"),
            (("100111100", 6, True), "101111100"),
            (("1111", 0, True), "1111"),
            (("1100", 1, True), "1110"),
        ],
        turn_x_given_bit_pos
    ),
    (
        [
            (("101111100", 5), "101100111"),
            (("101100", 5), "100011"),
            (("101", 2), "101"),
        ],
        small_number
    ),
    (
        [
            ("100011", ("000011", 5)),
            ("1011", ("0011", 3)),
            ("10101", ("10001", 2)),
        ],
        turn_off_next_one_after_zero
    ),
    (
        [
            (("010011", 4), "011100"),
            (("101100", 5), "111000"),
            (("101", 2), "110"),
        ],
        big_number
    )
)


if __name__ == '__main__':
    for in_out, test_fn in tests:
        evaluate(in_out=in_out, fn=test_fn)

