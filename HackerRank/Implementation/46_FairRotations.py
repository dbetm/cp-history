# https://www.hackerrank.com/challenges/fair-rations/problem
# Tag(s): Arrays, implementation

# idea: iterate over the array from n-1 to 0
def fairRations(B) -> str:
    cont = 0

    for i in range(len(B)-1, -1, -1):
        if B[i] & 1:
            if i == 0:
                return "NO"
            B[i] += 1
            B[i-1] += 1
            cont += 1

    return str(cont * 2)



if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))

    print(fairRations(arr))
