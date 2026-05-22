class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for char in tokens:
            if char in '+-/*':
                a = int(stack.pop())
                b = int(stack.pop())
                c = 0
                if char == '+':
                    c = a+b
                elif char == '-':
                    c = b-a
                elif char == '*':
                    c = b*a
                else:
                    c = b/a

                stack.append(c)
                
            else:
                stack.append(char)
            
        
        return int(stack.pop())

        