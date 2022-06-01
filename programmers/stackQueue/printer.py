def solution(priorities, location):
    sequence = 0
    while True:
        job = priorities.pop(0)
        if len(priorities) > 0 and job < max(priorities):
            priorities.append(job)
        else:
            if location == 0:
                sequence += 1
                break
            else:
                sequence += 1
        if location == 0:
            location = len(priorities) -1
        else: 
            location -= 1
    answer = sequence
    return answer

print(solution([1, 1, 9, 1, 1, 1], 0))
print(solution([2, 1, 3, 2], 2))

