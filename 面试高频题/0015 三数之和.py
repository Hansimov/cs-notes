class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3: return []
        res = []
        nums.sort()
        for i in range(0, len(nums)-2):
            if nums[i] > 0: break
            if i>0 and nums[i]==nums[i-1]:
                continue
            j = i + 1
            k = len(nums) - 1
            while j < k:
                sum_abc = nums[i] + nums[j] + nums[k]
                if sum_abc < 0:
                    j += 1
                    while j<k and nums[j]==nums[j-1]:
                        j += 1
                elif sum_abc > 0:
                    k -= 1
                    while j<k and nums[k]==nums[k+1]:
                        k -= 1
                else:
                    res.append([nums[i], nums[j], nums[k]])
                    j += 1
                    k -= 1
                    while j<k and nums[j]==nums[j-1]:
                        j += 1
                    while j<k and nums[k]==nums[k+1]:
                        k -= 1
        return res