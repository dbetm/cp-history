# WA
# Tags: 
pixels = dict() # diccionario de sets, fila: [columnas]

def check_existence(i, j) -> bool:
    if i not in pixels:
        pixels[i] = set()
        pixels[i].add(j)
        return True
    elif j not in pixels[i]:
        pixels[i].add(j)
        return True

    return False


def is_borde_pix(imagen, i, j, k) -> bool:
    n = len(imagen)
    m = len(imagen[0])
    # arriba
    if i-1 > 0 and imagen[i][j] - imagen[i-1][j] >= k:
        if check_existence(i, j):
            return True
    # arriba izq
    if i-1 > 0 and j-1 > 0 and imagen[i][j] - imagen[i-1][j-1] >= k:
        if check_existence(i, j):
            return True
    # arriba derecha
    if i-1 > 0 and j+1 < m and imagen[i][j] - imagen[i-1][j+1] >= k:
        if check_existence(i, j):
            return True
    # derecha
    if j+1 < m and imagen[i][j] - imagen[i][j+1] >= k:
        if check_existence(i, j):
            return True
    # izquierda
    if j-1 > 0 and imagen[i][j] - imagen[i][j-1] >= k:
        if check_existence(i, j):
            return True
    # abajo
    if i+1 < n and imagen[i][j] - imagen[i+1][j] >= k:
        if check_existence(i, j):
            return True
    # abajo derecha
    if i+1 < n and j+1 < m and imagen[i][j] - imagen[i+1][j+1] >= k:
        if check_existence(i, j):
            return True
    # abajo izquierda
    if i+1 < n and j-1 > 0 and imagen[i][j] - imagen[i+1][j-1] >= k:
        if check_existence(i, j):
            return True

    return False


if __name__ == '__main__':
    n, m, k = list(map(int, input().split()))

    imagen = []

    for i in range(n):
        col = list(map(int, input().split()))
        imagen.append(col)

    cont = 0
    for i in range(n):
        for j in range(m):
            if is_borde_pix(imagen, i, j, k):
                cont += 1

    print(cont)
