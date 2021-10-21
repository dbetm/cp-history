# https://app.codesignal.com/interview-practice/task/oJXTWuwEZiC6FTw3A/description
# Tag(s): DP

def climbingStairs(n):
    a, b = 1, 1

    for i in range(2, n+1):
        a, b = a + b, a

    return a

if __name__ == '__main__':
    n = int(input(''))

    print(climbingStairs(n))
