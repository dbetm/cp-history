# solved
# tags: implementation, sorting

def are_overlapping(inter1, inter2) -> bool:
    return inter1[1] >= inter2[0]


def mergeOverlappingIntervals(intervals):
    """My solution:
    Time: O(n * log (n))
    Space: O(n)
    """
    intervals.sort(key=lambda x: x[0])

    ans = [intervals[0]]

    n = len(intervals)

    for idx in range(1, n):
        if are_overlapping(ans[-1], intervals[idx]):
            ans[-1] = [ans[-1][0], max(ans[-1][1], intervals[idx][1])]
        else:
            ans.append(intervals[idx])

    return ans


if __name__ == "__main__":
    intervals = eval(input(""))

    print(mergeOverlappingIntervals(intervals))
