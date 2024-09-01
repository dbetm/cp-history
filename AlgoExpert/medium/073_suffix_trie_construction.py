# solved
# tags: trie, data-structures, strings

from pprint import pprint


# Do not edit the class below except for the
# populateSuffixTrieFrom and contains methods.
# Feel free to add new properties and methods
# to the class.
class SuffixTrie:
    def __init__(self, string):
        self.root = {}
        self.endSymbol = "*"
        self.populateSuffixTrieFrom(string)

    def populateSuffixTrieFrom(self, string):
        """My solution
        Time: O(n^2)
        Space: O(n^2)
        """
        node = self.root
        n = len(string)
        end_element = {self.endSymbol: True}

        for i in range(n-1, -1, -1):
            if i == (n-1):
                node[string[i]] = end_element.copy()
            elif string[i] not in node:
                node[string[i]] = dict()

            node = node[string[i]]
            for j in range(i+1, n):
                if j == (n-1):
                    node[string[j]] = end_element.copy()
                elif string[j] not in node:
                    node[string[j]] = dict()

                node = node[string[j]]

            node = self.root

        pprint(self.root)


    def contains(self, string) -> bool:
        """my solution
        Time: O(n)
        Space: O(1)

        Where n is the lenght of the input string to search
        """
        ans = True
        node = self.root

        for c in string:
            if c in node:
                node = node[c]
            else:
                ans = False
                break

        if not node.get("*"):
            ans = False

        return ans


if __name__ == "__main__":
    string = input(" ")
    trie = SuffixTrie(string)

    to_search = input(" ")

    print(trie.contains(to_search))