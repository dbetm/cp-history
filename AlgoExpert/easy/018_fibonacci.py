# solved
# tags: implementation, math


def getNthFib(n):
    """My solution:
    Time: O(n)
    Space: O(1)
    """
    fn2 = 0
    fn1 = 1

    if n == 1:
        return fn2
    
    if n == 2:
        return fn1

    ans = 1

    for _ in range(3, n+1):
        ans = fn1 + fn2
        fn2 = fn1
        fn1 = ans

    return ans


if __name__ == '__main__':
    n = int(input())

    print(getNthFib(n))