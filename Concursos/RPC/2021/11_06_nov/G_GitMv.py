# WA

def represent_delta(source:str, dest:str) -> str:
    ans = ''
    i, j = 0, 0
    n = len(source)
    m = len(dest)

    while(source[i] == dest[j]):
        ans += source[i] + '/'
        i += 1
        j += 1

    ans += '{'

    lim = n-1 if source[-1] == dest[-1] else n

    while i < lim:
        ans += source[i]

        i += 1

        if i < lim:
            ans += '/'

    ans += ' => '

    lim = m-1 if source[-1] == dest[-1] else m

    while j < lim:
        ans += dest[j]
        j += 1

        if j < lim:
            ans += '/'

    ans += '}'

    if dest[-1] == source[-1]:
        ans += '/' + dest[-1]

    return ans


if __name__ == '__main__':
    source = input().split(sep='/')
    dest = input().split(sep='/')

    print(represent_delta(source, dest))
