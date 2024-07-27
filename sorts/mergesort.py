def mergesort(arr):
    if len(arr) > 1: 
        q = len(arr)// 2
        left, right = arr[:q], arr[q:]
        mergesort(left)
        mergesort(right)    
        merge(arr, left, right)
    return 

def merge(arr, left, right):
    i = j = k = 0
    while i < len(left) and j < len(right): 
        if left[i] < right[j]:
            arr[k] = left[i]
            i += 1    
        else: 
            arr[k] = right[j]
            j += 1
        k += 1
    while i < len(left): 
        arr[k] = left[i]
        i += 1
        k += 1
    while j < len(right): 
        arr[k] = right[j]
        j += 1
        k += 1
    return 


arr = [0,3,7,1,5,4,6,2]
mergesort(arr)
print(arr)