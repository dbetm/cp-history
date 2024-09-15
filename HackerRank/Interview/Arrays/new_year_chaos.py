# https://www.hackerrank.com/challenges/new-year-chaos/problem
# tags: implementation, arrays
from typing import Union


def minimum_bribes(n: int, queue: list) -> Union[str, int]:
    """
    Time: O(n^2)
    Space: O(1)
    """
    total_bribes = 0

    for i in range(n):
        delta = (queue[i] - 1) - i

        if delta > 2:
            return "Too chaotic"

        # basicamente contar cuántas veces fue desplazado hasta atrás un elemento al contar los elementos mayores a él
        for j in range(max(0, queue[i]-2), i):
            if queue[j] > queue[i]:
                total_bribes += 1

    return total_bribes



if __name__ == "__main__":
    cases = int(input())

    for _ in range(cases):
        n = int(input())

        queue = list(map(int, input().split()))

        print(minimum_bribes(n, queue))
