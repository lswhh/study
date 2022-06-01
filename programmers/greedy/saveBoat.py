def solution(people, limit):
    people.sort()
    answer = 0
    if len(people) < 2:
        answer = 1
    else:
        needBoatCount = 0
        low = 0
        high = len(people) - 1
        while low <= high:
            if people[low] + people[high] <= limit and len(people) >= 2:
                low += 1
                high -=1
            else:
                high -=1
            needBoatCount += 1
        answer = needBoatCount

    return answer

print(solution([70, 50, 80, 50], 100)) #3
print(solution([70, 80, 50], 100))  #3
