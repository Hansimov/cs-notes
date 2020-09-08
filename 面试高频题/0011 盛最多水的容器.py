class Solution:
    def maxArea(self, height: List[int]) -> int:
        if not height: return 0
        left = 0
        right = len(height)-1
        res = 0
        while left < right:
            min_h = min(height[left], height[right])
            res = max(res, min_h*(right-left))
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return res