# https://omegaup.com/arena/problem/tonsOfBits#problems
if __name__ == '__main__':
    bin = raw_input()
    j = 0
    n = 0;
    for i in range(len(bin)):
        if(bin[len(bin)-i-1] == '1'):
            n += pow(2, j)
        j += 1
    print(n)
