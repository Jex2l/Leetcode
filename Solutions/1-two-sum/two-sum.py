class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        sets = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in sets:
                return [sets[complement], i]
            sets[num] = i
        return