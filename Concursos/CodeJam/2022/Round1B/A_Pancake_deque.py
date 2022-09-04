

def compute(n, levels):
    ans = 0
    max_level = 0
    left = 0
    right = n-1

    while left <= right:
        if levels[left] <= levels[right]:
            if levels[left] >= max_level:
                max_level = levels[left]
                ans += 1
            left += 1
        else:
            if levels[right] >= max_level:
                max_level = levels[right]
                ans += 1
            right -= 1

    return ans

if __name__ == '__main__':
    t = int(input())

    for i in range(t):
        n = int(input())
        levels = list(map(int, input().split()))

        print(f"Case #{i+1}: {compute(n, levels)}")
