# https://www.hackerrank.com/challenges/separate-the-numbers/problem
# Tag(s): strings, implementation

def separate_words(s):
    if s[0] == '0':
        return 'NO'

    n = len(s)
    ans = 'NO'

    for i in range(1, (n // 2) + 1):
        start = 0
        end = i
        first_element = s[start:end]
        num = first_element

        while end < n:
            x = str(int(num) + 1)

            if end + len(x) > n:
                break

            cont = 0
            for t in range(end, end + len(x)):
                if s[t] != x[cont]:
                    break
                cont += 1
            else:
                start = end
                end = end + len(x)
                num = s[start:end]
                continue
            break

        else:
            ans = 'YES {}'.format(first_element)
            break

    return ans



if __name__ == '__main__':
    q = int(input())

    for i in range(q):
        s = input()
        print(separate_words(s))
