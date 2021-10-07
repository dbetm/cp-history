# https://app.codesignal.com/interview-practice/task/yM4uWYeQTHzYewW9H/description
# Tag(s): strings, arrays

def isCryptSolution(crypt, solution):
    ans = True
    solution_dict = {item[0] : item[1] for item in solution}

    a = ''.join(solution_dict[letter] for letter in crypt[0])
    b = ''.join(solution_dict[letter] for letter in crypt[1])
    c = ''.join(solution_dict[letter] for letter in crypt[2])

    if (a != '0' and a[0] == '0') or (b != '0' and b[0] == '0') or (c != '0' and c[0] == '0'):
        ans = False
    else:
        ans = (int(a) + int(b)) == int(c)

    return ans


if __name__ == '__main__':
    crypt = list(input().split())

    n = int(input())

    solution = []

    for i in range(n):
        mapping = list(input().split())
        solution.append(mapping)

    print(isCryptSolution(crypt, solution))
