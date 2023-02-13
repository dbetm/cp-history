# https://www.hackerrank.com/challenges/game-of-thrones/problem
# tag(s): strings, implementation


def is_a_possible_palin(s: str) -> bool:
    is_odd_lenght = len(s) & 1
    ans = True

    count_by_char = dict()

    for c in s:
        if c in count_by_char:
            count_by_char[c] += 1
        else:
            count_by_char[c] = 1

    tolerance = 1 if is_odd_lenght else 0
    # check that we can create pairs for each character
    for x in count_by_char.values():
        if x & 1 and tolerance > 0:
            tolerance -= 1
        elif x & 1:
            ans = False
            break
        else:
            continue
    
    return ans



if __name__ == '__main__':
    s = input()

    print("YES" if is_a_possible_palin(s) else "NO")