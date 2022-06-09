def binarySearch(aList, aSearchData):
    start = 0
    end = len(aList) - 1
    mid = start
    while start <= end:
        mid = (start + end) // 2
        if aList[mid] == aSearchData:
            return mid
        elif aList[mid] > aSearchData:
            end = mid - 1
        else: # aList[mid] < aSearchData:
            start = mid + 1
    return -1

print(binarySearch([1, 9, 100 , 1000, 2001], 2000)) #-1
print(binarySearch([1, 9, 100 , 1000, 2001], 2001)) #4
print(binarySearch([1, 9, 100 , 1000, 2001], 1)) #0
print(binarySearch([1, 9, 100 , 1000, 2001], 100)) #2