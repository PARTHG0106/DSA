class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        count0 = 0
        n = len(nums)
        for i in nums:
            if(i == 0):
                count0 += 1
            if(count0 > 1):
                return [0] * n

        track0 = 0
        if count0 == 1:
            track0 = 1

        totalProd = 1
        for i in nums:
            if i != 0:
                totalProd *= i
        
        ans = [0] * n
        for i in range(0, n):
            if(nums[i] != 0 and track0 == 1):
                ans[i] = 0
            elif(nums[i] != 0 and track0 == 0):
                ans[i] = int(totalProd / nums[i])
            else:
                ans[i] = totalProd

        return ans