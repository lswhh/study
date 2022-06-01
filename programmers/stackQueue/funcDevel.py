
from collections import Counter


def solution(progresses, speeds):
    result = []
    nextReleaseDay = 0
    for i in range(0, len(progresses)):
        remainWork = 100 - progresses[i]
        remainDay, y = divmod(remainWork,speeds[i])
        if y > 0:
            remainDay += 1
        if nextReleaseDay < remainDay:
            nextReleaseDay = remainDay
        result.append(nextReleaseDay)
    c = Counter(result)
    answer = list(c.values())
    return answer

print(solution([95, 90, 99, 99, 80, 99],	[1, 1, 1, 1, 1, 1]))