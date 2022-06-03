# https://programmers.co.kr/learn/courses/30/lessons/42627
import heapq
INF = 0xFFFFFFFF

def solution(jobs):
    curJobCompleteTime = 0
    q = []
    resultList = []
    heapq.heapify(jobs)

    while len(jobs) > 0:
        startT, runT = heapq.heappop(jobs)
        if (startT >= curJobCompleteTime and len(q) == 0) or (len(q) == 0 and len(jobs) == 0):
            curJobCompleteTime = max(startT, curJobCompleteTime) + runT
            resultList.append((startT, curJobCompleteTime))
        else:
            if startT >= curJobCompleteTime:
                heapq.heappush(jobs,(startT, runT))
            else:
                endT = curJobCompleteTime + runT
                heapq.heappush(q,(endT, startT, runT))

        if (startT >= curJobCompleteTime and len(q) > 0) or (len(jobs) == 0 and len(q) > 0):
            endT, startT, runT = heapq.heappop(q)
            resultList.append((startT, endT))
            curJobCompleteTime = endT
            while len(q) > 0:
                endT, startT, runT = heapq.heappop(q)
                heapq.heappush(jobs,(startT, runT))

    answer = 0            
    count = 0
    totalSum = 0
    while resultList:
        job = resultList.pop(0)
        startTime = job[0]
        jobTime = job[1]
        # print(startTime, jobTime, jobTime - startTime)
        count += 1 
        totalSum += jobTime - startTime
    if count != 0:
        answer = round(totalSum/count)
    
    return answer

print(solution([[0, 3], [1, 9], [2, 6]]))
print(solution([[0, 3], [1, 9], [2, 6], [5,1]]))
print(solution([[0, 3], [1, 9], [2, 6], [20,1]]))
print(solution([[0, 3]]))