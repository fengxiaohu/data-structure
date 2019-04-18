class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        j=0
        dst=[]
        for i in range(0,len(nums)):
            if nums[i]!=val:
                nums[j]=nums[i]
                j=j+1
                
        return j
       
                
        
        