"""
* 二分查找有几种写法？它们的区别是什么？ - 知乎 
    * https://www.zhihu.com/question/36132386
"""

def lower_bound(arr, target): # 返回 arr 中第一个不小于 target 的值的索引
    left, right = 0, len(arr)
    while left < right: # 搜索空间为 [left, right)，左闭右开，非空
        mid = left+(right-left)//2 # 防溢出
        if arr[mid]<target: # upper_bound() 将 < 改成 <= 即可，返回的是第一个大于 target 的索引
            left = mid + 1
        else:
            right = mid
    return left # 无论返回 left 还是 right 都是对的，因为退出循环条件，表明 [left, right] 为空，则二者重合

arr = [5,7,8,8,8,9]
target = 8
print(lower_bound(arr,8))