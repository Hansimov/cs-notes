"""
* 面试题41. 数据流中的中位数（优先队列 / 堆，清晰图解） - 数据流中的中位数 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/solution/mian-shi-ti-41-shu-ju-liu-zhong-de-zhong-wei-shu-y/
* heapq --- 堆队列算法 — Python 3.8.5 文档 
    * https://docs.python.org/zh-cn/3/library/heapq.html
"""

import heapq
class MedianFinder:

    def __init__(self):
        self.a = [] # 较大一半数，小顶堆，个数：N/2 向上取整
        heapq.heapify(self.a) # len is >= max_heap
        self.b = [] # 较小一半数，大顶堆，个数：N/2 向下取整
        heapq.heapify(self.b) 

    def addNum(self, num: int) -> None:
        if len(self.a) != len(self.b): # 加入前总共奇数个数，因此加入 a 之后，还需弹出最小值（并取反）加入 b
            heapq.heappush(self.b, -heapq.heappushpop(self.a, num))
        else: # 加入前总共偶数个数，因此加入 b 之后，还需弹出最大值（并取反）加入 a
            heapq.heappush(self.a, -heapq.heappushpop(self.b, -num))

    def findMedian(self) -> float:
        if len(self.a) != len(self.b):
            return self.a[0]
        else:
            return (self.a[0] - self.b[0])/2

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()