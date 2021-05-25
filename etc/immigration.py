def binary_search(array, target):
    start = 0
    end = len(array)
    while start <= end:
        mid = (start + end) // 2
        if array[mid] == target:
            return mid
        elif array[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
    return None

# def get_next_times(current_times, times):
#     next_times = current_times
#     for i in range(0, len(times)):
#         next_times[i] = current_times[i] + times[i] 
#     return next_times

def get_next_times(current_times, times):
    next_times = [0] * len(current_times)
    min_idx = 0

    for i in range(0, len(times)):
        next_times[i] = current_times[i] + times[i] 
        if ( next_times[min_idx] > next_times[i] ):
            min_idx = i
    return min_idx

def solution(n, times):
    current_times = [0] * len(times)
    #next_times = [0] * len(times)

    for i in range(0, n):
        min_idx = get_next_times(current_times, times)
        current_times[min_idx] = current_times[min_idx] + times[min_idx]
    
    answer = current_times[min_idx] 
    return answer

#print(get_next_times([7,10],[7,10]))
print(solution(6,[7,10]))