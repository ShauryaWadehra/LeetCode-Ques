class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-x for x in stones]
        heapq.heapify(stones)
        while len(stones)>1:
            temp1 = heapq.heappop(stones)
            temp2 = heapq.heappop(stones)
            if temp1 !=temp2:
                heapq.heappush(stones,-abs(temp1-temp2))
        return abs(stones[0]) if len(stones) else 0