# https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem
# tags: hashmap, eof


if __name__ == "__main__":
    n = int(input())

    phone_book = dict()

    for _ in range(n):
        name, phone_number = input().split(" ")

        phone_book[name] = phone_number

    while True:
        try:
            name = input()
            if name in phone_book:
                print(f"{name}={phone_book[name]}")
            else:
                print("Not found")
        except EOFError:
            break
