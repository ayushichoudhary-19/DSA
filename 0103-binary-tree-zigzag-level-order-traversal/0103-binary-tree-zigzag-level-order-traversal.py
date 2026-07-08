# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


from collections import deque
class Solution:
    
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []

        if not root:
            return ans

        q = deque([root])
        levelnum = 0
        while q:
            level = []
            # even levels are straight
            levelnum += 1
            for _ in range(len(q)):
                node = q.popleft()
                if levelnum%2 == 0:
                    level.append(node.val)
                else:
                    #inserts the value at the beginning of the list
                    level.insert(0,node.val)
                
                if node.right:
                    q.append(node.right)
                if node.left:
                    q.append(node.left)
            
            ans.append(level)

        return ans