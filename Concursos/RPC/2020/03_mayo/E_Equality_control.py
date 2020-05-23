from math import *
from sys import stdin, stdout
import random

# WA
# Tag(s): Implementation, Math

prob1 = 10
prob2 = 10
f_prob1 = True
f_prob2 = False

def concat(lista1, lista2):
    lista1.extend(lista2)
    return lista1

def shuffle(lista):
    random.shuffle(lista)
    global prob1
    global prob2
    if(f_prob1):
        prob1 *= (1000 / len(lista))
    else:
        prob2 *= (1000 / len(lista))
    return lista

def sorted(lista):
    lista.sort()
    return lista

if __name__ == '__main__':
    expr1 = stdin.readline()
    expr2 = stdin.readline()

    # lista1 = eval(expr1)
    # f_prob1 = False
    # f_prob2 = True
    # lista2 = eval(expr2)
    # # print("prob1 ", prob1)
    # # print("prob2 ", prob2)
    # if(len(lista1) != len(lista2)):
    #     print("not equal")
    # elif(prob1 == prob2):
    #     print("equal")
    # else:
    #     print("not equal")

    try:
        lista1 = eval(expr1)
        f_prob1 = False
        f_prob2 = True
        lista2 = eval(expr2)
        if(len(lista1) != len(lista2)):
            print("not equal")
        elif(prob1 == prob2):
            print("equal")
        else:
            print("not equal")
    except Exception as e:
        print("equal")
        # if(random.randint(0,2) == 1):
        #
        # else:
        #     print("not equal")
    # print(*lista1)
    # print(*lista2)
