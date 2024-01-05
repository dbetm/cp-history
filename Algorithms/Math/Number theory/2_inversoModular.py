def encontrarInversoModular(a, c):
    for i in range(c):
        if(((a%c) * (i%c)) % c == 1):
            return i
    return -1

a = int(input("A: "))
c = int(input("C: "))

b = encontrarInversoModular(a, c)
if(b != -1):
    print("El inverso modular " + str(a) + " mod " + str(c) + " es: " + str(b))
else:
    print("No hay inverso modular para: " + str(a) + " mod " + str(c))
