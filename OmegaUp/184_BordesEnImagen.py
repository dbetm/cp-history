pixels = dict() # diccionario de sets, fila: [columnas]

def check_existence(i, j) -> bool:
    if not pixels[i]:
        pixels[i] = set()
        pixels[i].insert(j)
        return True
    elif j not in pixels[i]:
        pixels[i].insert(j)
        return True

    return False


def is_borde_pix(imagen, i, j, k) -> bool:
    # arriba
    if i-1 > 0 and imagen[i][j] - imagen[i-1][j] > k:
        if check_existence(i, j):
            return True
    # arriba izq
    if i-1 > 0 and j-1 > 0 and imagen[i][j] - imagen[i-1][j] > k:
        if check_existence(i, j):
            return True
    # arriba derecha
    # derecha
    # izquierda
    # abajo
    # abajo derecha
    # abajo izquierda

    return False

if __name__ == '__main__':
    n, m, k = list(map(int, input().split()))

    imagen = []

    for i in range(n):
        col = list(map(int, input().split()))
        imagen.append(col)

    pri
