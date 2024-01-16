#
# tags:


def minimumWaitingTime(queries):
    """My solution
    Time; O(n log(n))
    Space: O(1)
    """
    queries.sort()
    ans = 0
    last_sum = 0
    n = len(queries)

    for idx, query in enumerate(queries):
        if idx == (n-1):
            break
        ans += query + last_sum
        last_sum = (query + last_sum)

    return ans

def minimumWaitingTime2(queries):
    # Proposal, same complexity as my solutin
    queries.sort()
    total = 0
    n = len(queries)

    for idx, query in enumerate(queries):
        total += query * (n - idx - 1)

    return total



if __name__ == "__main__":
    queries = list(map(int, input().rstrip().split(" ")))

    print(minimumWaitingTime(queries))
    print(minimumWaitingTime2(queries))