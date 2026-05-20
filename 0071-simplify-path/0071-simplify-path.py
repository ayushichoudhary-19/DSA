class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []

        currStr = ''
        i = 1
        while i < len(path):
            k = i

            while k < len(path) and path[k] != '/':
                k += 1
            
            currStr = path[i:k]

            if currStr == '' or currStr == '/' or currStr == '.':
                pass
            
            elif currStr == '..':
                if stack:
                    stack.pop()

            else:
                stack.append(currStr)

            i = k+1

        return '/' + '/'.join(stack)