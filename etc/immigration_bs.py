from bisect import bisect_left

def solution(n, times):
    next_times = [[0,0]] * len(times)
    list(sorted(times)).sort()
    for i in range(0 , len(times)):
        next_times[i] = [times[i], times[i]]
    # first person
    next_times.sort()
    print(next_times)

    for i in range(0, n - 1):
        selected_examiner_next_time = next_times.pop(0)
        selected_examiner_next_time[0] = selected_examiner_next_time[0] + selected_examiner_next_time[1]
        idx = bisect_left(next_times, selected_examiner_next_time)
        next_times.insert(idx, selected_examiner_next_time)
    print(next_times)
    answer = next_times[0][0]
    return answer

#print(get_next_times([7,10],[7,10]))
print(solution(6,[7,10]))