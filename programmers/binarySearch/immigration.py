# https://programmers.co.kr/learn/courses/30/lessons/43238

def solution(n, times):
    list(times).sort()
    min_time = 1
    max_time = times[len(times) - 1] * n

    answer = max_time
    while min_time <= max_time:
        mid_time = (min_time + max_time) // 2
        sum = 0
        for i in range(0, len(times)):
            sum += mid_time // times[i]
            if sum > n:
                break

        if n > sum:
            min_time = mid_time + 1
        else: # n <= sum
            max_time = mid_time - 1
            answer = mid_time

    return answer

print(solution(6,[7,10]))