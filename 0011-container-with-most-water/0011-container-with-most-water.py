class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l,r,maxa = 0, len(heights) -1, 0 
        while l<r:
            a = min(heights[l],heights[r])*(r-l)
            if heights[l] < heights[r]:
                l+=1
            else:
                r-=1
            maxa = max(maxa,a)
        return maxa