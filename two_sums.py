class Two_Sum:
    def twoSum(self, nums, target):
        """
        Given an array of ints, return the indices of the two numbers such that 
        they add up to the specific target
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        all_nums = {}
        for i in range(len(nums)):
            if all_nums.get(target - nums[i]) is not None:
                return [all_nums[target - nums[i]], i]
            all_nums[nums[i]] = i
        return None