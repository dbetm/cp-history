# solved
# tags: implementation


def majorityElement(array):
    """My solution
    Time: O(n)
    Space: O(1)
    """
    candidate = array[0]
    cont = 1

    for num in array:
        if num == candidate:
            cont += 1
        else:
            cont -= 1

            if cont == 0:
                candidate = num
                cont = 1
    
    return candidate


def majorityElement2(array):
    """Proposal
    Time: O(n)
    Space: O(1)
    """
    NUM_BITS = 32
    threshold_len = len(array) / 2
    answer = 0 # here we will sum the power of two of the majority element

    for current_bit in range(0, NUM_BITS):
        current_bit_value = 1 << current_bit
        cont_matching_bit_value = 0

        for num in array:
            if current_bit_value & num != 0:
                cont_matching_bit_value += 1

        if cont_matching_bit_value > threshold_len:
            answer += current_bit_value

    return answer


if __name__ == "__main__":
    arr = list(map(int, input().split()))

    print(majorityElement(arr))
    print(majorityElement2(arr))