

def solution(n, times):
    list(times).sort()
    min_time = 1
    max_time = times[len(times) - 1] * n
    max_int = 1e10
    print("max_int : ",max_int)
    answer = max_time
    while min_time <= max_time:
        mid_time = (min_time + max_time) // 2
        sum = 0
        for i in range(0, len(times)):
            sum += mid_time // times[i]

        if n > sum:
            min_time = mid_time + 1
        else: # n <= sum
            max_time = mid_time - 1
            answer = mid_time

    return answer

#print(get_next_times([7,10],[7,10]))
print(solution(6,[7,10]))