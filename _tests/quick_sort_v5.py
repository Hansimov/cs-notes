import random

# [b,e]
def partition(arr, b, e):
    k = random.randint(b,e)
    nums[e], nums[k] = nums[k], nums[e]
    pivot = arr[e] # choose
    t = b
    for i in range(b, e):
        if arr[i] <= pivot:
            arr[i], arr[t] = arr[t], arr[i]
            t += 1
    arr[e], arr[t] = arr[t], arr[e]
    return t

def quick_sort(arr, b, e):
    if b < e:
        sep = partition(arr, b, e)
        quick_sort(arr, b, sep-1)
        quick_sort(arr, sep+1, e)

if __name__ == "__main__":
    nums = list(range(10))
    random.shuffle(nums)
    print(nums)
    quick_sort(nums, 0, len(nums)-1)
    print(nums)