class Solution:
    def isValid(self, b: str) -> bool:
        mapping = {')' : '(', '}':'{', ']' :'['}
        stack = []
        for s in b:
            if s not in mapping:
                stack.append(s)
                continue 
            if not stack or stack[-1] != mapping[s]:
                return False
            stack.pop()
        return not stack