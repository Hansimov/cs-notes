class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        left, right = 0, len(nums)
        while left < right:
            mid = left + (right-left)//2
            if nums[mid] == mid:
                left = mid + 1
            else:
                right = mid
        return left