#
# tags:



from typing import List


def get_max_after_queries(n: int, queries: list) -> int:
    """My solution
    Time: O(max(m, n))
    Space: O(n)

    Nota: N could be up to 10^7 and m up to 10^5 
    """
    arr = [0] * (n+1)

    for (a, b, k) in queries:
        arr[a] += k

        if (b + 1) < (n+1):
            arr[b+1] -= k

    acc_sum = 0
    max_sum = 0
    for i in range(1, n+1):
        acc_sum += arr[i]

        if acc_sum > max_sum:
            max_sum = acc_sum

    return max_sum


def get_max_after_queries2(n: int, queries: list) -> int:
    """Proposal from editorial
    Time: O(m * log(m))
    Space: O(m) # 2*m
    """
    deltas: List[tuple] = list()

    for (a, b, k) in queries:
        deltas.append((a, k))
        deltas.append((b+1, -1*k))

    deltas.sort()

    acc_sum = 0
    max_sum = 0
    
    for (_, delta) in deltas:
        acc_sum += delta

        max_sum = max(max_sum, acc_sum)

    return max_sum



if __name__ == "__main__":
    n, num_queries = list(map(int, input().split()))
    queries = list()

    for i in range(num_queries):
        # a b k
        query = list(map(int, input().split()))
        queries.append(query)

    print(get_max_after_queries2(n, queries))
