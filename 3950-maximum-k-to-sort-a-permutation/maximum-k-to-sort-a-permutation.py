class Solution(object):
    def sortPermutation(self, nums):
        k=-1
        for i in range(len(nums)):
            if(i!=nums[i]):
                if(k==-1):
                     k=nums[i]
                else:
                    k&=nums[i]
        return 0 if k==-1 else k
        