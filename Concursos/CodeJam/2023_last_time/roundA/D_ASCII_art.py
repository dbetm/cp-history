# not solved
# tag(s): math, implementation

if __name__  == "__main__":
    t = int(input())

    for case in range(1, t+1):
        n = int(input())
        i = 2

        while True:
            # so bad
            x = int(26 * i * (i - 1) * 0.5)

            if x > n:
                i -= 1
                break

            i += 1

        # offset = x - n
        # print(offset, i)
        # cont = 0
        # for k in range(65, 65 + 26):
        #     letter = chr(k)

        #     exit = False
        #     for o in range(i):
        #         if cont >= offset:
        #             print(f"Case #{case}: {letter}")
        #             exit = True
        #             break
        #     if exit:
        #         break

        #     cont += 1

