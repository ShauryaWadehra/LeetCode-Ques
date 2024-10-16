class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        mp = {}
        for num in nums:
            mp[num]  = mp.get(num,0) + 1
            if mp[num] > 1:
                return True
        return False