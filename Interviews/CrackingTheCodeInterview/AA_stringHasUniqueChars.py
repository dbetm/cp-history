import sys

"""Determine if a string has all unique characters. What if you can not use
additional data structures?
Use a bit vector:
Time Complexity: O(n)
Extra space complexity: O(1)
"""

def isUniqueChars(_str):
    checker = 0
    ans = True

    for char in _str:
        val = ord(char)

        if checker & (1 << val) > 0:
            ans = False
            break

        checker |= (1 << val)
        print('Number of the checker in bytes: ', sys.getsizeof(checker))

    return ans

if __name__ == '__main__':
    _str = input('Type the string: ')

    if isUniqueChars(_str):
        print('All chars are unique in {0}'.format(_str))
    else:
        print('Some chars aren\'t unique')
