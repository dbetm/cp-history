# solved
# tag(s): data-structures, stack


# Feel free to add new properties and methods to the class.
class MinMaxStack:
    """My solution
    Time: O(1)
    Space: O(1)
    """

    def __init__(self):
        self.maxx = list()
        self.minn = list()
        self.data = list()

    def peek(self):
        return self.data[-1]

    def pop(self):
        num = self.data.pop()

        if num == self.maxx[-1]:
            self.maxx.pop()
        if num == self.minn[-1]:
            self.minn.pop()

        return num

    def push(self, number):
        self.data.append(number)

        if len(self.maxx) == 0 or number >= self.maxx[-1]:
            self.maxx.append(number)
        if len(self.minn) == 0 or number <= self.minn[-1]:
            self.minn.append(number)

    def getMin(self):
        return self.minn[-1]

    def getMax(self):
        return self.maxx[-1]


if __name__ == "__main__":
    stack = MinMaxStack()

    ## TEST CASE #1
    stack.push(5)
    print(stack.getMin())
    print(stack.getMax())
    print(stack.peek())
    print("--------------")
    stack.push(7)
    print(stack.getMin())
    print(stack.getMax())
    print(stack.peek())
    stack.push(2)
    print("--------------")
    print(stack.getMin())
    print(stack.getMax())
    print(stack.peek())
    print(stack.pop())
    print(stack.pop())
    print(stack.getMin())
    print(stack.getMax())
    print(stack.peek())
