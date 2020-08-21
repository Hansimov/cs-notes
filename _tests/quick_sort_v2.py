import random

# [b,e)
def quick_sort(arr: list, b: int, e: int):
    if e-b<=1: return
    pivot = arr[b]
    t = b + 1 # 位置 t 左侧的数都小于等于 pivot
    for i in range(b+1, e):
        if arr[i] <= pivot:
            arr[i], arr[t] = arr[t], arr[i]
            t += 1
    arr[t-1], arr[b] = arr[b], arr[t-1]
    quick_sort(arr, b, t-1)
    quick_sort(arr, t, e)

if __name__ == '__main__':
    nums = list(range(20))
    random.shuffle(nums)
    print(nums)
    quick_sort(nums, 0, len(nums))
    print(nums)

