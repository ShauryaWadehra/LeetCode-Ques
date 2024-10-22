class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def dfs(root):
            if not root:
                return [True,0]
            left, right = dfs(root.left), dfs(root.right)
            b = left[0] and right[0] and (abs(left[1]-right[1]) <=1)
            return [b, max(left[1],right[1]) + 1]
        return dfs(root)[0]