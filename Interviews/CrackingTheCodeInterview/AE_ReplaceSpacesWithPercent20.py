
def format_spaces_url(str):
    str = str.replace(' ', '%20')

    return str


if __name__ == '__main__':
    str = input('Type your string: ')

    print(format_spaces_url(str))
