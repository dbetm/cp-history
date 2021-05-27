# https://www.hackerrank.com/challenges/find-a-string/problem
# tag(s): Strings, windows

def count_substring(string, sub_string):
    n = len(sub_string)
    m = len(string)
    num_occurrences = 0

    for i in range(0, m - n + 1):
        if sub_string == string[i:i+n]:
            num_occurrences += 1

    return num_occurrences

if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()

    count = count_substring(string, sub_string)
    print(count)
