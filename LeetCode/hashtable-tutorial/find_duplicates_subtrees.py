from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    
    def __str__(self):
        return f"(left){self.left}<{self.val}>{self.right}(right)"


class Solution:

    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        duplicates = list()
        subtrees = dict()

        def dfs(node: TreeNode):
            if node is None:
                return ""

            left = dfs(node.left)
            right = dfs(node.right)

            # we add the l char to differentiate when there's no left or right node
            subtree_key = f"l{left}{node.val}{right}r"

            subtrees[subtree_key] = subtrees.get(subtree_key, 0) + 1

            if subtrees[subtree_key] == 2:
                duplicates.append(node)

            return subtree_key

        dfs(root)

        return duplicates



if __name__ == "__main__":
    sol = Solution()

    four1 = TreeNode(4)
    two1 = TreeNode(2, left=four1)

    four2 = TreeNode(4)
    two2 = TreeNode(2, left=four2)
    four3 = TreeNode(4)
    three1 = TreeNode(3, left=two2, right=four3)

    root = TreeNode(1, left=two1, right=three1)

    print(sol.findDuplicateSubtrees(root))