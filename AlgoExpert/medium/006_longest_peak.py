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


if __name__ == "__main__":
    array = list(map(int, input().rstrip().split(" ")))
    
    print(longestPeak(array))
