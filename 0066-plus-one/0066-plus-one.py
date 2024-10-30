class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits = digits[::-1]
        i,j = 1,0
        while i:
            if j < len(digits):
                if digits[j] == 9:
                    digits[j] = 0
                else:
                    digits[j] += 1
                    i = 0
            else:
                digits.append(i)
                i=0
            j+=1
        return digits[::-1]