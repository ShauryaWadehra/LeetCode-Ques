class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        for i,a in enumerate(nums):
            if nums[i]>0:
                break
            if i >0 and a == nums[i-1]:
                continue
            l,r = i+1,len(nums)-1
            while l<r:
                curr = a + nums[l] + nums[r]
                if curr >0:
                    r-=1
                elif curr < 0 :
                    l+=1
                else:
                    res.append([a,nums[l],nums[r]])
                    l+=1
                    r-=1
                    while nums[l] == nums[l-1] and l<r:
                        l+=1

        return res