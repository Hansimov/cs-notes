import random

# [b,e]
def parition(arr, b, e) -> int:
    pivot = arr[b]
    t = b + 1
    for i in range(b+1,e+1):
        if arr[i] <= pivot:
            arr[i], arr[t] = arr[t], arr[i]
            t += 1
    arr[b], arr[t-1] = arr[t-1], arr[b]
    return t-1

def quick_sort(arr, b, e):
    if b>=e: return
    sep = parition(arr, b, e)
    quick_sort(arr, b, sep-1)
    quick_sort(arr, sep+1, e)

if __name__ == "__main__":
    nums = list(range(10))
    random.shuffle(nums)
    print(nums)
    quick_sort(nums, 0, len(nums)-1)
    print(nums)
