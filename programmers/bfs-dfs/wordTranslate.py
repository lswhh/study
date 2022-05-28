# https://programmers.co.kr/learn/courses/30/lessons/43163
import copy
import sys
sys.setrecursionlimit(10**6)
def available(sourceStr, targetStr):
    diffCount = 0
    for i in range(len(sourceStr)):
        if sourceStr[i] != targetStr[i]:
            diffCount += 1
    if diffCount > 1:
        return False
    return True

def dfs(begin, target, remain):
    global remainWordsCount
    if len(remain) == 0: 
        return 
    if available(begin, remain[0]) == True:
        begin = remain[0]
        del remain[0]
    else:
        return

    if begin == target:
        if remainWordsCount < len(remain):
            remainWordsCount = len(remain)
        return

    for i in range(len(remain)):
        dfs(begin, target, reArrange(remain,i))
    return

def reArrange(source, startIdx):
    result = []
    for i in range(startIdx, len(source)):
        result.append(source[i])
    for i in range(0, startIdx):
        result.append(source[i])
    return result

remainWordsCount = -1
def solution(begin, target, words):
    global remainWordsCount

    for i in range(len(words)):
        dfs(begin, target, reArrange(words,i))
    if remainWordsCount != -1:
        answer = len(words) - remainWordsCount
    else : 
        answer = 0
    return answer



print(solution("hit","cog", ["hot", "dot", "dog", "lot", "log", "cog"]))	#4
remainWordsCount = -1
print(solution("hit","cog", ["hot", "dot", "dog", "lot", "log"]))	#0

from collections import deque

minCount = 0xFFFFFFFF
def bfs(begin, words, start, visited, target):
    global minCount
    if available(begin, words[start]) != True:
        return
    queue = deque([start])
    visited[start] = 1    

    while queue:
        v = queue.popleft()
        if words[v] == target:
            if visited[v] < minCount:
                minCount = visited[v]
        begin = words[v]
        for i, word in enumerate(words):
            if visited[i] == 0 and available(begin, word) == True:
                queue.append(i)
                visited[i] = visited[v] + 1
    return 

def solution(begin, target, words):
    count = 0
    for i in range(len(words)):
        visited = [0] * len(words)
        bfs(begin, words, i, visited, target)
    if minCount != 0xFFFFFFFF:
        count = minCount
    else: 
        count = 0
    return count

print(solution("hit","cog", ["hot", "dot", "dog", "lot", "log", "cog"]))	#4
minCount = 0xFFFFFFFF
print(solution("hit","cog", ["hot", "dot", "dog", "lot", "log"]))	#0