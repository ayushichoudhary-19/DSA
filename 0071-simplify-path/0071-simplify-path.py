class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []

        for part in path.split('/'):
            if part in ['', '.']:
                continue
            
            elif part == '..':
                if stack:
                    stack.pop()
                
            else:
                stack.append(part)


        return '/' + '/'.join(stack)