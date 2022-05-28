# https://programmers.co.kr/learn/courses/30/lessons/43165
count = 0
def dfs(numbers, target, idx, result):
    global count
    if idx == len(numbers):
        calcValue = 0
        for i in result:
            calcValue += i
        if calcValue == target: 
            count += 1
        return result
    result[idx] = -numbers[idx]
    result = dfs(numbers, target, idx + 1, result)
    
    result[idx] = numbers[idx]
    result = dfs(numbers, target, idx + 1, result)
    
    return result
def solution(numbers, target):
    result = [0] * len(numbers)
    dfs(numbers, target, 0, result)
    answer = count
    return answer

print(solution([1, 1, 1], 3))
print(solution([1, 1, 1, 1, 1], 3))