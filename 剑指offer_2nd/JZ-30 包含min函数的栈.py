"""
* 面试题30. 包含 min 函数的栈（辅助栈，清晰图解） - 包含min函数的栈 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/solution/mian-shi-ti-30-bao-han-minhan-shu-de-zhan-fu-zhu-z/
"""

class MinStack:

    def __init__(self):
        self.a = []
        self.b = []

    def push(self, x: int) -> None:
        self.a.append(x)
        if not self.b or x <= self.b[-1]:
            self.b.append(x)

    def pop(self) -> None:
        if self.a.pop() == self.b[-1]:
            self.b.pop()

    def top(self) -> int:
        return self.a[-1]

    def min(self) -> int:
        return self.b[-1]

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.min()