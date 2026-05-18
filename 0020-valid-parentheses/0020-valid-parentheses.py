class Solution:
    def isValid(self, s: str) -> bool:
        stack = []


        for ch in s:
            if ch == '{' or ch == '(' or ch=='[':
                stack.append(ch)
            
            else:
                if ch == '}' and len(stack) != 0 and stack.pop() == '{':
                    continue
                
                elif ch == ')' and len(stack) != 0 and stack.pop() == '(':
                    continue
                
                elif ch == ']' and len(stack) != 0 and stack.pop() == '[':
                    continue

                else:
                    return False
            
        return len(stack) == 0
                

        
        