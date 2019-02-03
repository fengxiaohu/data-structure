# brute force
# use two loop to search the target

class Solution:
    def two_sum(self, nums, target):
        res=[]
        for i in range(len(nums)):
            for j in range(len(nums)):
                if nums[i]+nums[j] == target:
                    res = [nums[i], nums[j]]
                    return res
                elif nums[j] == target:
                    res.append(target)
                    return res

'''
Test = Solution
nums = [1, 2, 3, 4, 5]
target = 6
Test.two_sum(nums, target)
'''








