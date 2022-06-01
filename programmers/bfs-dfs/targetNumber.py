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
count = 0
print(solution([1, 1, 1, 1, 1], 3))
count = 0
print(solution([4, 1, 2, 1], 4))



count = 0
def dfs(numbers, target, index, result):
    global count
    if index == len(numbers):
        if result == target:
            count += 1
            return count
        return count
    dfs(numbers, target, index + 1, result + numbers[index])
    dfs(numbers, target, index + 1, result - numbers[index])
    return count

def solution(numbers, target):
    answer = 0
    answer += dfs(numbers, target, 0, 0)
    return answer
    
print(solution([1, 1, 1], 3))
count = 0
print(solution([1, 1, 1, 1, 1], 3))
count = 0
print(solution([4, 1, 2, 1], 4))
# from collections import Counter, deque
# from itertools import combinations

# def dfs(numbers, target):
#     count = 0
#     q = deque()
#     q.append(([numbers[0]], 0))
#     q.append(([-numbers[0]], 0))    
#     numbersLen = len(numbers)

#     while q:
#         resultList, idx = q.pop()
#         if len(resultList) == numbersLen:
#             result = sum(resultList)
#             if result == target:
#                 count += 1
#             continue
        
#         newResult = resultList[:]
#         newResult.append(numbers[idx+1])
#         q.append((newResult, idx+1))
#         newResult = resultList[:]
#         newResult.append(-numbers[idx+1])
#         q.append((newResult, idx+1))

#     return count

# def solution(numbers, target):
    
#     answer = dfs(numbers, target)
#     return answer
# print(solution([1, 1, 1, 1, 1], 3))
# print(solution([4, 1, 2, 1], 4))


