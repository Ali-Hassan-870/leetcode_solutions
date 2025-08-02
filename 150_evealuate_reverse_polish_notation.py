from typing import List
import math

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for t in tokens:
            if t not in "+-*/":
                stack.append(int(t))
            else:
                y, x = stack.pop(), stack.pop()
                match t:
                    case '+':
                        stack.append(x + y)
                    case '-':
                        stack.append(x - y)
                    case '*':
                        stack.append(x * y)
                    case '/':
                        div = x / y
                        if div < 0:
                            stack.append(math.ceil(div))
                        else:
                            stack.append(math.floor(div))

        return stack[0]

output = Solution().evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"])
print(output)
