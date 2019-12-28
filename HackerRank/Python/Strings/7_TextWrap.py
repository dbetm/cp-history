import textwrap

def wrap(string, max_width):
    wrapper = textwrap.TextWrapper(width=max_width)
    palabras = wrapper.wrap(text=string)
    ans = ""
    for line in palabras:
        ans += line + "\n"
    return ans

if __name__ == '__main__':
    string, max_width = input(), int(input())
    result = wrap(string, max_width)
    print(result)
