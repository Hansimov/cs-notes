"""
* 面试题39. 数组中出现次数超过一半的数字（摩尔投票法，清晰图解） - 数组中出现次数超过一半的数字 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/solution/mian-shi-ti-39-shu-zu-zhong-chu-xian-ci-shu-chao-3/
"""

# class Solution:
#     def majorityElement(self, nums: List[int]) -> int:
#         if not nums:
#             return None
#         hash_map = {}
#         max_cnt, max_num = 0, nums[0]
#         for num in nums:
#             if hash_map.__contains__(num):
#                 hash_map[num] += 1
#             else:
#                 hash_map[num] = 1

#             if hash_map[num] > max_cnt:
#                 max_cnt+=1
#                 max_num = num
#         return max_num

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        vote = 0
        for num in nums:
            if vote == 0:
                maj = num
            vote += 1 if num == maj else -1
        return maj