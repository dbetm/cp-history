from typing import List
from collections import Counter


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freqs = dict(Counter(nums))

        inv_freqs = dict()
        max_freq = -1
        min_freq = 10e6
        top_k_frequent = list()

        for value, freq in freqs.items():
            inv_freqs[freq] = inv_freqs.get(freq, list()) + [value]

            if freq > max_freq:
                max_freq = freq
            if freq < min_freq:
                min_freq = freq

        for freq in range(max_freq, min_freq - 1, -1):
            if freq in inv_freqs:
                top_k_frequent += inv_freqs[freq]

            if len(top_k_frequent) == k:
                break

        return top_k_frequent


