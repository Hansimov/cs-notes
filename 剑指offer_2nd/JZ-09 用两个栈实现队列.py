"""
* 面试题09. 用两个栈实现队列（清晰图解） - 用两个栈实现队列 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/solution/mian-shi-ti-09-yong-liang-ge-zhan-shi-xian-dui-l-2/
"""

class CQueue:

    def __init__(self):
        self.a = []
        self.b = []

    def appendTail(self, value: int) -> None:
        self.a.append(value)

    def deleteHead(self) -> int:
        if self.b:
            return self.b.pop()
        if not self.a:
            return -1
        while self.a:
            self.b.append(self.a.pop())
        return self.b.pop()

# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()