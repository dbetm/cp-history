# https://www.hackerrank.com/contests/software-engineer-prep-kit/challenges/top-k-frequent-events-with-order-preservation/problem
# Tag(s): HashMap, dictionary

from collections import Counter, defaultdict


def getTopKFrequentEvents(events, k):
    indexes = dict()
    """
    - Having a dictionary with the index (the minor where each event happen to be)
    - Count frecuencies (counts)
    - Reverse counts map, the value now is a list of keys and key is the frequency
    - Sort frecuencies and take the k higher
    - Compile final results checking the k higher frequencies in reverse counts
    """

    for idx, event in enumerate(events):
        if event not in indexes:
            indexes[event] = idx
    
    counts = Counter(events)
    reverse_counts = defaultdict(list)

    for event, freq in counts.items():
        reverse_counts[freq].append(event)

    frequencies = list(reverse_counts.keys())
    frequencies.sort(reverse=True)

    result = list()

    for top_freq in frequencies[:k]:
        candidates = reverse_counts[top_freq]
        candidates.sort(key=lambda x: indexes[x])

        slice_size = min(len(candidates), k - len(result))
        result.extend(candidates[:slice_size])

        if len(result) == k: # >= k
            break

    return result


if __name__ == '__main__':
    
    events = list(map(int, input("").split(" ")))

    k = int(input("").strip())

    result = getTopKFrequentEvents(events, k)
    print('\n'.join(map(str, result)))