"""
* 面试题53 - I. 在排序数组中查找数字 I（二分法，清晰图解） - 在排序数组中查找数字 I - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/solution/mian-shi-ti-53-i-zai-pai-xu-shu-zu-zhong-cha-zha-5/
* 二分查找有几种写法？它们的区别是什么？ - 知乎 
    * https://www.zhihu.com/question/36132386
"""
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def lower_bound(arr, tar):
            left, right = 0, len(arr)
            while left < right:
                mid = left + (right-left)//2
                if arr[mid] < tar:
                    left = mid + 1
                else:
                    right = mid
            return left
        return lower_bound(nums,target+1) - lower_bound(nums,target)
