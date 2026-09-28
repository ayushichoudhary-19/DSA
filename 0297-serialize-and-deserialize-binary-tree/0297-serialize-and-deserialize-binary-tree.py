# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    
    def preorder(self,root,preorder_string):
        if root is None:
            preorder_string.append('N')
            return
        
        preorder_string.append(str(root.val))
        
        self.preorder(root.left,preorder_string)
        self.preorder(root.right,preorder_string)

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """

        preorder_string = []

        self.preorder(root, preorder_string)

        print(preorder_string)
        return ",".join(preorder_string)

    def deserialize(self, data):
        preorder_array = data.split(',')
        i = 0

        def build():
            nonlocal i

            if preorder_array[i] == 'N':
                i += 1
                return None

            root = TreeNode(int(preorder_array[i]))
            i += 1

            root.left = build()
            root.right = build()

            return root

        return build()
            

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))