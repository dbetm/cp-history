# Dynamic Programming Solution for
# Palindrome Partitioning Problem

# Regresa el número mínimo de cortes necesarios para particionar una
# cadena tal que cada parte sea un palindromo.
def minPalPartion(str):
    # Obtener la longitud de la cadena
    n = len(str)
    # Creamos dos arreglos para construir la solución, bottom up manner
    # C[i][j] = Mínimo número de cortes necesarios para el palindromo particionado
    # de la subcadena str[i...j]

    # P[i][j] = true, si la subcadena str[i...j] es palindromo, de otra forma false.
    # Nota que C[i][j] es 0 si P[i][j] es true (es palindromo).
    # Los inicializamos, C en 0 todas las casillas
    C = [[0 for i in range(n)]
            for i in range(n)]
    P = [[False for i in range(n)]
                for i in range(n)]
    # Diferentes variables para iterar
    j = 0
    k = 0
    L = 0
    # Cada subcadena de longitud 1 es un palindromo
    for i in range(n):
        P[i][i] = True
        C[i][i] = 0
    # L es la longitud de la subcadena. Se construye la solución hacia arriba
    # considerando todos las subcadenas de longitud (2 hasta n).
    # La estructura iterativa es la misma usada en Matrix Chain Multiplication
    for L in range(2, n+1):
        # Para cada subcadena de longitud L, se fijan los diferentes índices iniciales
        for i in range(n - L + 1):
            j = i + L - 1 # Fijar el índice final
            # Si L es 2, entonces solo se necesitan comparar 2 caracteres
            # De otra forma, se necesitan checar los caracteres esquina
            # y el valor de P[i+1][j-1].
            if(L == 2):
                P[i][j] = (str[i] == str[j])
            else:
                P[i][j] = ((str[i] == str[j]) and P[i+1][j-1])
            # Si str[i...j] es palindromo, entonces C[i][j] = 0
            if(P[i][j] == True):
                C[i][j] = 0
            else:
                # Hacer un corte en cada posible posición comenzando desde i hasta j
                # y obtener el costo mínimo de corte.
                C[i][j] = 100000000
                for k in range(i, j):
                    C[i][j] = min(C[i][j], C[i][k] + C[k+1][j] + 1)
    # retornar el resultado
    return C[0][n-1]



# Código manejador
str = input("Escribe la cadena: ")
print("El mínimo número de cortes para el palindromo particionado es: ", minPalPartion(str))
