# https://www.hackerrank.com/challenges/weighted-uniform-string/problem
# Tag(s): strings, data structures

def query_weigthed_uniform_strings(s, n, queries):
    m = len(s)
    weights = set()

    weights.add(ord(s[0])-96)
    cont = 1

    for i in range(1, m):
        if s[i] == s[i-1]:
            cont += 1
            weights.add((ord(s[i])-96) * cont)
        else:
            cont = 1
            weights.add(ord(s[i])-96)

    answers = []

    for q in queries:
        if q in weights:
            answers.append('Yes')
        else:
            answers.append('No')

    return answers


if __name__ == '__main__':
    s = input()
    n = int(input())
    queries = []

    for i in range(n):
        x = int(input())
        queries.append(x)

    answers = query_weigthed_uniform_strings(s, n, queries)

    for ans in answers:
        print(ans)
