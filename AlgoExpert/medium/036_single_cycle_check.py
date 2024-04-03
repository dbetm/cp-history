# solved
# tags: implementation, graph traversal

def hasSingleCycle(array):
    """My solution (optimized space with hints)
    Time: O(n)
    Space: O(1)
    """
    start_index = 0
    current_index = 0
    n = len(array)
    counter = 0
    ans = True

    while True:
        print(f"{current_index = }")
        if (current_index + array[current_index]) < 0:
            delta = abs(array[current_index]) % n
            
            if (current_index - delta) < 0:
                extra = abs(current_index - delta)
                current_index = n - extra
            else:
                current_index = current_index - delta
        else:
            current_index = (current_index + array[current_index]) % n
        
        counter += 1
        print(f"next_index = {current_index}")
        print("------")
        if current_index == start_index and counter == n:
            break
        elif current_index == start_index and counter != n or (counter > n):
            ans = False
            break

    return ans


if __name__ == "__main__":
    arr = list(map(int, input().split()))

    print(hasSingleCycle(arr))
