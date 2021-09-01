# accepted
if __name__ == '__main__':
    n = int(input())
    skills = list(map(int, input().split()))

    skills.sort()

    ans = 0

    for i in range(0, n-1, 2):
        ans += abs(skills[i] - skills[i+1])

    print(ans)
