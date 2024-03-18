# solved
# tags: dynamic programming, bottom-up


def levenshteinDistance(str1, str2):
    """My solution
    Time: O(n*m)
    Space: O(m)
    """
    n = len(str2)
    m = len(str1)

    dp = [ list(range(0, m+1)), [0 for _ in range(0, m+1)] ]
    down, top = 0, 1
    ans = 0

    for i in range(0, n):
        dp[top][0] = i+1

        for j in range(1, m+1):
            if str1[j-1] == str2[i]:
                dp[top][j] = dp[down][j-1]
            else:
                insert = dp[down][j]
                delete = dp[top][j-1]
                replace = dp[down][j-1]

                dp[top][j] = 1 + min(min(insert, delete), replace)

        ans = dp[top][-1]
        down, top = top, down

    return ans


if __name__ == "__main__":
    str1 = input("")
    str2 = input("")

    print(levenshteinDistance(str1, str2))
