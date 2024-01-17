# solved 
# tags: implementation, greedy


def custom_sort(item):
    return item["payment"], item["deadline"]


def optimalFreelancing(jobs):
    """Proposal
    Time: O(nlog(n))
    Space: O(1)

    The fundamental idea is considering the most profitable jobs first and then
    take them as late as possible. Beause we know the limit of seven 7, so we can 
    look for each chosen job the best day to take inside the week.
    """
    week = [0 for _ in range(7)]

    # order the jobs by the payment
    jobs = sorted(jobs, key=lambda x : x["payment"], reverse=True)
    taken_jobs = 0
    #print(jobs)

    for job in jobs:
        payment = job["payment"]
        deadline = job["deadline"]

        start_idx = min(deadline - 1, 6)

        for idx in range(start_idx, -1, -1):
            if week[idx] == 0:
                week[idx] = payment
                taken_jobs += 1
                break

        if taken_jobs == 7:
            break

    return sum(week)


if __name__ == '__main__':
    n = int(input())
    jobs = list()

    for _ in range(n):
        deadline, payment = list(map(int, input().split(" ")))
        jobs.append({"deadline": deadline, "payment": payment})

    print(optimalFreelancing(jobs))