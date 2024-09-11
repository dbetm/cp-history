# solved
# tags: cursors, pointers, implementation, array, greedy


def is_local_min(idx, scores):
    n = len(scores)

    if idx == 0 or idx == (n-1):
        return False

    return scores[idx] < scores[idx+1] and scores[idx] < scores[idx-1]



def minRewards(scores: list) -> list:
    """My solution - with hints
    Time: O(n)
    Space: O(n) - because of rewards array
    """
    n = len(scores)

    if n == 1:
        return 1
    if n == 2:
        return 3

    rewards = [0] * n

    for idx in range(n):
        if rewards[idx] != 0:
            continue

        if is_local_min(idx, scores):
            rewards[idx] = 1

            left = idx-1
            while left >= 0 and rewards[left] == 0 and scores[left] > scores[left+1]:
                rewards[left] = rewards[left + 1] + 1
                left -= 1

            if left >= 0:
                if scores[left] > scores[left+1] and rewards[left] <= rewards[left+1]:
                    rewards[left] = rewards[left + 1] + 1

            right = idx+1
            while right < n and scores[right] > scores[right-1]:
                rewards[right] = rewards[right-1] + 1
                right += 1

    if rewards[0] == 0:
        rewards[0] = 1
    if rewards[-1] == 0:
        rewards[-1] = 1

    return sum(rewards)


def minRewards2(scores: list) -> list:
    """Proposal - similar to v1 - but more simple
    Time: O(n)
    Space: O(n)
    """
    n = len(scores)

    rewards = [1] * n

    # assign rewards to incresing ranges from left to right
    for i in range(1, n):
        if scores[i] > scores[i-1]:
            rewards[i] = rewards[i-1] + 1

    # assign rewards to increasing ranges from right to left
    for i in range(n-2, -1, -1):
        if scores[i] > scores[i+1]:
            rewards[i] = max(rewards[i], rewards[i+1] + 1)

    return sum(rewards)



if __name__ == "__main__":
    scores = list(map(int, input().split(" ")))

    print(minRewards2(scores))