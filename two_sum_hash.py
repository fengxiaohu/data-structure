class Solution2:
    def two_sum_hash(self,nums,target):
        map={}
        # python dictionary {key:val,key1:val1,...}
        # dict[key]=val
        for i in range(len(nums)):
            if nums[i] not in map:
                map[target-nums[i]]=i+1
            else:
                return map[nums[i]],i+1


Test_hash_method = Solution2
my_nums=[1,2,3,4,5]
my_target=7
Test_hash_method.two_sum_hash(my_nums,my_target)
