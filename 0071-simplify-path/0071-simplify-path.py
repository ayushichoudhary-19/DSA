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

            if currStr == '/' or currStr == '.':
                i = k+1
                continue
            
            elif currStr == '..':
                if len(stack) > 0:
                    stack.pop()

            else:
                if currStr != '':
                    stack.append(currStr)

            i = k+1

        result = ''

        for st in stack:
            result += '/' + st
        
        if result == '':
            return '/' 
        else:
            return result