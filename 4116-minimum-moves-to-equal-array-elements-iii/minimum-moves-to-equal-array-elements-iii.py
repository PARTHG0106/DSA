class Solution:
    def minMoves(self, nums: List[int]) -> int:
        maxi = 0
        moves = 0
        for x in nums:
            maxi = max(x, maxi)
        
        for x in nums:
            moves = moves + maxi - x
        
        return moves