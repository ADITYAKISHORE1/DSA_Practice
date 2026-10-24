class Solution(object):
    def minOperations(self, nums):
        inf=1e9
        n=len(nums)
        pos0 = nums.index(0)
        forward=True
        backward=True
        for i in range(n):
            if(nums[(i+pos0)%n]!=i):
                forward=False
            if(nums[(pos0-i+n)%n]!=i):
                backward=False
        ans=inf
        if forward:
            ans=min(ans,pos0)
            ans=min(ans,2+(n-pos0)%n)
        if backward:
            ans=min(ans,1+(n-1-pos0))
            ans=min(ans,1+(pos0+1)%n)
        return -1 if ans==inf else ans