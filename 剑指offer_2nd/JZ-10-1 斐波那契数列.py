class Solution:
    def fib(self, n: int) -> int:
        a = 0
        b = 1
        for i in range(n):
            sum = (a+b) % 1000000007
            a = b
            b = sum
        return a