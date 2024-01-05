def contarDigitos(n):
    ans = 0
    while n > 0:
        ans += 1
        n //= 10
    return ans;

numDigitos = contarDigitos(123456)
print(numDigitos)
