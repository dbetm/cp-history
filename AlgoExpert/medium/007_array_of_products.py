# solved
# tags: pointers, math


def arrayOfProducts(array):
    """My solution
    Time: O(n)
    Space: O(n)

    The requirement of the problem is not used division operation.
    """
    left_products = list()
    left_product = 1
    right_products = list()
    right_product = 1
    ans = list()
    n = len(array)

    left = 0
    right = n - 1

    while left < n:
        left_product = left_product * array[left]
        left_products.append(left_product)
        left += 1

        right_product = right_product * array[right]
        right_products.append(right_product)
        right -= 1
    
    right_products.reverse()
    # print(left_products)
    # print(right_products)

    for idx in range(n):
        left_product = 1
        right_product = 1

        if idx - 1 >= 0:
            left_product = left_products[idx-1]
        if idx + 1 < n:
            right_product = right_products[idx+1]
        
        #print(f"idx={idx}, left={left_product}, right={right_product}")

        ans.append(left_product * right_product)

    return ans


if __name__ == "__main__":
    arr = list(map(int, input().split()))

    print(arrayOfProducts(arr))
