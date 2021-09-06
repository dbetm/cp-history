import math
# https://www.hackerrank.com/challenges/stat-warmup/problem
import numpy as np
from scipy import stats

T = 1.96

if __name__ == '__main__':
    n = int(input())
    arr = np.array(list(map(int, input().split())))

    mean = np.mean(arr)
    median = np.median(arr)
    mode_list = list(stats.mode(arr).mode)
    mode_list.sort()
    mode = mode_list[0]
    sd = np.std(arr)
    standard_error = sd / math.sqrt(n)
    lower_b_confidence_interval_mean = mean - (T * standard_error)
    upper_b_confidence_interval_mean = mean + (T * standard_error)

    print('{:.1f}'.format(mean))
    print('{:.1f}'.format(median))
    print(mode)
    print('{:.1f}'.format(sd))
    print('{:.1f} {:.1f}'.format(
        lower_b_confidence_interval_mean,
        upper_b_confidence_interval_mean
    ))
