# solved
# tags: strings, implementation


def is_ip_valid(ip: str) -> bool:
    octets = ip.split(".")

    if len(octets) != 4:
        return False

    ans = True

    for octet in octets:
        if len(octet) > 1 and octet[0] == "0":
            ans = False
            break

        numerical = int(octet)

        if numerical < 0 or numerical > 255:
            ans = False
            break
    
    return ans



def validIPAddresses(string):
    """My solution
    Time: O(1) (doesn't matter the input, in the worst case always be compute 3^4 ops)
    Space: O(1)
    """
    ans = []
    n = len(string)

    for idx, o1 in enumerate(range(0, min(3, n))):
        ip = string[0:o1+1] + "."
        print(f"{ip=}")
        for jdx, o2 in enumerate(range(min(o1+1, n), min(o1+4, n))):
            ip_l2 = ip + string[o2-jdx:o2+1] + "."
            print(f"{ip_l2=}")
            for kdx, o3 in enumerate(range(min(o2+1, n), min(o2+4, n))):
                ip_l3 = ip_l2 + string[o3-kdx:o3+1] + "."
                print(f"{ip_l3=}")
                for ldx, o4 in enumerate(range(min(o3+1, n), min(o3+4, n))):
                    ip_l4 = ip_l3 + string[o4-ldx:n]

                    print(f"{ip_l4=}")
                    print("////")
                    if is_ip_valid(ip_l4):
                        ans.append(ip_l4)

                    break

        print("*"*12)

    return ans


if __name__ == "__main__":
    string = input()

    print(validIPAddresses(string))


