# solved
# tags: recursion, binary tree, map, sets


class UnionFind:
    # My solution
    def __init__(self):
        self.data = dict()

    def createSet(self, value):
        # Time: O(1)
        self.data[value] = {"set_id": value, "values": {value}}

    def find(self, value):
        # Time: O(1)
        # Space: O(1)
        return self.data.get(value, dict()).get("set_id", None)

    def union(self, valueOne, valueTwo):
        # Time: O(n)
        # Space: O(1)
        print(f"before union between {valueOne} and {valueTwo}")
        print(self.data)
        set_id1 = self.data.get(valueOne, dict()).get("set_id", None)
        set_id2 = self.data.get(valueTwo, dict()).get("set_id", None)
        print("sets_ids", set_id1, set_id2)

        if (set_id1 is not None and set_id2 is not None) and set_id1 != set_id2:
            set_1: set = self.data[set_id1]["values"]
            set_2: set = self.data[set_id2]["values"]

            for val in set_2:
                set_1.add(val)
                self.data[val]["set_id"] = set_id1
                self.data[val]["values"] = set() # empty set

        print(f"after union between {valueOne} and {valueTwo}")
        print(self.data)


class UnionFind2:
    # Proposal 1
    def __init__(self):
        self.parents = {}

    # O(1) time | O(1) space 
    def createSet(self, value):
        # self reference
        self.parents[value] = value

    # O(n) time | O(1) space 
    def find(self, value):
        if value not in self.parents:
            return None

        currentParent = value
        while currentParent != self.parents[currentParent]:
            currentParent = self.parents[currentParent]

        return currentParent

    # O(n) time | O(1) space 
    def union(self, valueOne, valueTwo):
        if valueOne not in self.parents or valueTwo not in self.parents:
            return

        valueOneRoot = self.find(valueOne)
        valueTwoRoot = self.find(valueTwo)

        self.parents[valueTwoRoot] = valueOneRoot


class UnionFind3:
    # Proposal 2 - More efficient
    def __init__(self):
        self.parents = {}
        self.ranks = {}

    # O(1) time | O(1) space 
    def createSet(self, value):
        # self reference
        self.parents[value] = value
        # ranks save the height of the current subset (tree)
        self.ranks[value] = 0

    # O(alpha(n)) aprox. O(1) time | O(alpha(n)) aprox. O(1) space (because of recursion)
    # where α(n) is the inverse Ackermann function
    def find(self, value):
        if value not in self.parents:
            return None

        # PATH COMPRESSION 
        #  The idea is to flatten the tree when find() is called. When find() is called for an element x, 
        # root of the tree is returned. The find() operation traverses up from x to find root. The idea 
        # of path compression is to make the found root as parent of x so that we don’t have to traverse 
        # all intermediate nodes again. If x is root of a subtree, then path (to root) from all nodes 
        # under x also compresses.
        if value != self.parents[value]:
            self.parents[value] = self.find(self.parents[value])

        return self.parents[value]

    # O(alpha(n)) aprox. O(1) time | O(alpha(n)) aprox. O(1) space (because of recursion)
    def union(self, valueOne, valueTwo):
        if valueOne not in self.parents or valueTwo not in self.parents:
            return

        valueOneRoot = self.find(valueOne)
        valueTwoRoot = self.find(valueTwo)

        # how to choose which will be the children of the another? we use the rank
        if self.ranks[valueOneRoot] < self.ranks[valueTwoRoot]:
            self.parents[valueOneRoot] = valueTwoRoot
        elif self.ranks[valueOneRoot] > self.ranks[valueTwoRoot]:
            self.parents[valueTwoRoot] = valueOneRoot
        else:
            self.parents[valueTwoRoot] = valueOneRoot
            self.ranks[valueOneRoot] += 1


if __name__ == "__main__":
    union_find = UnionFind()

    try:
        while True:
            action_call = input("")
            res = eval(f"union_find.{action_call}")
            print(action_call, " = ", res)
    except EOFError:
        print("EOF reached")
