#!/usr/bin/env python
# -*- coding: utf-8 -*-
from operator import xor

entrada = raw_input()

entrada = entrada.replace("TRUE", "True").replace("FALSE", "False").replace("NOT", "not")


if entrada.startswith('AND'):
    nn = entrada.replace('AND', '').replace(',', ' and ')
    print eval(nn)
elif entrada.startswith('OR'):
    nn = entrada.replace('OR', '').replace(',', ' or ')
    print eval(nn)
elif entrada.startswith('NAND'):
    nn = entrada.replace('NAND', '').replace(',', ' not and ')
    print eval(nn)
elif entrada.startswith('NOR'):
    nn = entrada.replace('NOR', '').replace(',', ' not or ')
    print eval(nn)
elif entrada.startswith('XOR'):
    nn = entrada.replace('XOR', '').replace(',', ' ^ ')
    print eval(nn)
else:
    print eval(entrada)
