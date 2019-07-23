def scalarProduct(a, b):
    assert len(a) == len(b)
    a, b = sorted(a), sorted(b)
    return sum(a[i] * b[i] for i in range(len(a)))

if __name__== '__main__':
    a = [1, 3, 6, 8]
    b = [7, 23, 1, 0]
    print(scalarProduct(a, b))
