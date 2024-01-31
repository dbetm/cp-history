# solved
# tags: implementation


def longestPeak(array):
    """My solution:
    Time: O(n)
    Space: O(1)
    """
    longest_peak = 0
    n = len(array)
    idx = 1

    len_current_peak = 1

    while idx < n:
        if array[idx] > array[idx-1]:
            len_current_peak += 1
            #print(array[idx], "increasing >>")
        elif array[idx] == array[idx-1]:
            #print("reseting because valley")
            len_current_peak = 1
        else:
            if len_current_peak > 1:
                #print(array[idx], "decreasing")
                idx += 1
                len_current_peak += 1

                while idx < n:
                    if array[idx] < array[idx-1]:
                        len_current_peak += 1
                        idx += 1
                        #print(array[idx], "decreasing")
                    else:
                        idx -= 1
                        break
                
                #print(f"current_peak", len_current_peak)
                if len_current_peak >= 3 and len_current_peak > longest_peak:
                    #print(len_current_peak, longest_peak, "+"*13)
                    longest_peak = len_current_peak

            len_current_peak = 1

        idx += 1

    return longest_peak


def longestPeak2(array):
    """Proposal based on explanation:
    Time: O(n)
    Space: O(1)

    It intends to be more easy to write this solution.
    The basic idea is two separate the task of findings peak and then
    look for the longest one.
    """
    longest_peak = 0
    n = len(array)
    idx = 1

    while idx < (n-1):
        # check if there is a peak
        if array[idx-1] < array[idx] > array[idx+1]:
            left = idx
            right = idx
            cont = 1
            # expand to left
            while left > 0:
                if array[left] > array[left-1]:
                    cont += 1
                    left -= 1
                else:
                    break
            # expand to right
            while right < (n-1):
                if array[right] > array[right+1]:
                    cont += 1
                    right += 1
                else:
                    break

            # check if the current peak is the longest so far
            longest_peak = max(longest_peak, cont)

            idx = right + 1
        else:
            idx += 1

    return longest_peak


if __name__ == "__main__":
    array = list(map(int, input().rstrip().split(" ")))

    print(longestPeak(array))
    print(longestPeak2(array))
