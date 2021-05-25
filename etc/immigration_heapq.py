import heapq

def get_next_times(current_times, times):
    next_times = [0] * len(current_times)
    min_idx = 0

    for i in range(0, len(times)):
        next_times[i] = current_times[i] + times[i] 
        if ( next_times[min_idx] > next_times[i] ):
            min_idx = i
    return min_idx

def solution(n, times):
    next_times = [[0,0]] * len(times)
    h = []
    # list(sorted(times)).sort()
    for i in range(0 , len(times)):
        next_times[i] = [times[i], times[i]]
        heapq.heappush(h,next_times[i])

    # first person
    # next_times.sort()
    # print(next_times)
    # print(h)
    for i in range(0, n - 1):
        selected_examiner_next_time = heapq.heappop(h)
        selected_examiner_next_time[0] = selected_examiner_next_time[0] + selected_examiner_next_time[1]
        heapq.heappush(h,selected_examiner_next_time)
        # idx = bisect_left(next_times, selected_examiner_next_time)

        # next_times.insert(idx, selected_examiner_next_time)
    # print(next_times)
    # print(h)
    answer = heapq.heappop(h)[0]
    return answer

#print(get_next_times([7,10],[7,10]))
print(solution(6,[7,10]))