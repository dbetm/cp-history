# solved
# tags: implementation, pointers


def taskAssignment(k, tasks):
    """My solution
    Time: O(nlog(n))
    Space: O(n)
    """
    tasks_n_idxs = [(task, i) for i, task in enumerate(tasks)]
    tasks_n_idxs = sorted(tasks_n_idxs, key=lambda x : x[0])

    left = 0
    right = len(tasks) - 1
    answers = list()

    while left < right:
        answers.append([tasks_n_idxs[left][1], tasks_n_idxs[right][1]])
        left += 1
        right -= 1

    return answers


if __name__ == "__main__":
    k = int(input())
    task_times = list(map(int, input().split()))

    print(taskAssignment(k, task_times))
