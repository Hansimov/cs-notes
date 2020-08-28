"""
* 【Python】详解：为何添加辅助队列就能实现O(1)操作？ - 队列的最大值 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/solution/python-xiang-jie-wei-he-tian-jia-fu-zhu-dui-lie-ji/

* 如何解决 O(1) 复杂度的 API 设计题 - 队列的最大值 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/solution/ru-he-jie-jue-o1-fu-za-du-de-api-she-ji-ti-by-z1m/
* 面试题59 - II. 队列的最大值 - 队列的最大值 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/solution/mian-shi-ti-59-ii-dui-lie-de-zui-da-zhi-by-leetcod/
"""

import collections
class MaxQueue:

    def __init__(self):
        self.a = collections.deque() # normal queue
        self.b = collections.deque() # sorted queue

    def max_value(self) -> int:
        return self.b[0] if self.b else -1

    def push_back(self, value: int) -> None:
        self.a.append(value)
        while self.b and self.b[-1] < value:
            self.b.pop()
        self.b.append(value)

    def pop_front(self) -> int:
        if not self.a:
            return -1
        res = self.a.popleft()
        if res == self.b[0]:
            self.b.popleft()
        return res

# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()