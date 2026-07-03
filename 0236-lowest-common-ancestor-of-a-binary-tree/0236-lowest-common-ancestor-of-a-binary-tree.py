# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def findPath(self,root,target,path):
        if not root:
            return False

        path.append(root)

        if root is target:
            return True

        if self.findPath(root.left,target,path) or self.findPath(root.right,target,path):
            return True

        path.pop()
        return False

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':

        # lowest
        # i love you cutuuuuu
        # mt preshan ho hojaega sb thik
        # mzeee krenge weekend is onnnnnn
        # yayyyyyyyy
        # nhakr aajau fr pyar krunga apko bott sara

        pathA = []
        pathB = []

        self.findPath(root,p,pathA)
        self.findPath(root,q,pathB)

        i = 0
        while i < len(pathA) and i < len(pathB):
            if pathA[i] != pathB[i]:
                break
            i += 1
            
        return pathA[i-1]
