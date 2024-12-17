class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = defaultdict(int)
        maxcount = 0
        l = 0
        for r in range(len(s)):
            count[s[r]]+=1
            maxcount = max(maxcount,count[s[r]])
            if r - l + 1 - maxcount > k:
                count[s[l]]-=1
                l+=1
        return r-l+1