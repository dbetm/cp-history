# Alternativa: Grafos, Dijsktra

def compute_customer(pressures, p, reverse=False):
    total = 0

    if not reverse:
        for i in range(1, p):
            total += pressures[i] - pressures[i-1]
    else:
        for i in range(p-2, -1, -1):
            total += pressures[i+1] - pressures[i]

    return total


def compute(n, p, pressures):
    p_total = 0
    last_product_pressure = pressures[0][-1]
    p_total += last_product_pressure

    for i in range(1, n):
        front_diff = abs(last_product_pressure - pressures[i][0])
        back_diff = abs(last_product_pressure - pressures[i][-1])

        if back_diff < front_diff:
            p_total += back_diff
            p_total += compute_customer(pressures[i], p, reverse=True)
            last_product_pressure = pressures[i][0]
        else:
            p_total += front_diff
            p_total += compute_customer(pressures[i], p, reverse=False)
            last_product_pressure = pressures[i][-1]

    return p_total


if __name__ == '__main__':
    t = int(input())

    for i in range(t):
        customer_pressures = []
        n, p = list(map(int, input().split()))

        for _ in range(n):
            pressures = list(map(int, input().split()))
            pressures.sort()
            customer_pressures.append(pressures)

        print(f"Case #{i+1}: {compute(n, p, customer_pressures)}")
