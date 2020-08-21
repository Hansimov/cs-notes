"""
* 面试题03. 数组中重复的数字 （哈希表 / 原地交换，清晰图解） - 数组中重复的数字 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/solution/mian-shi-ti-03-shu-zu-zhong-zhong-fu-de-shu-zi-yua/
* java的4种解法 - 数组中重复的数字 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/solution/java-de-4chong-jie-fa-by-sdwwld/
"""

# class Solution:
#     def findRepeatNumber(self, nums: List[int]) -> int:
#         hash_map = {}
#         for num in nums:
#             if num in hash_map:
#                 return num
#             else:
#                 hash_map[num] = 1
#         return -1


# class Solution:
#     def findRepeatNumber(self, nums: List[int]) -> int:
#         hash_map = set()
#         for num in nums:
#             if num in hash_map:
#                 return num
#             else:
#                 hash_map.add(num)
#         return -1

class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        if not nums:
            return -1
        i = 0
        while i < len(nums):
            if nums[i] == i:
                i += 1
                continue
            if nums[nums[i]] == nums[i]:
            # 由上一条判断语句知，nums[i] != i
            # 故此条件若为真，则表明必有 j 满足 nums[j] == nums[i]，且 j != i
            # 故 nums[i] 即为重复数字
                return nums[i]
            else:
                nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
        return -1


