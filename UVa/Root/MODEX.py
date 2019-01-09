def calcularZ(x, y, n):
    x = x % n
    resultado = 1
    while(y > 0):
        if(y & 1):
            resultado = resultado * x % n
        x = x * x % n
        y = y >> 1
    return resultado

n = int(input())

for i in range(n):
    x, y, n = map(int, input().split())
    print(calcularZ(x, y, n))

input() # read the zero
