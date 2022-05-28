# https://programmers.co.kr/learn/courses/30/lessons/43162
from collections import deque

def bfs(graph, start, visited):
    global count
    queue = deque([start])
    while queue:
        v = queue.popleft()
        visited[start] = True

        for i, isConnect in enumerate(graph[v]):
            if not visited[i] and isConnect == 1:
                queue.append(i)
                visited[i] = True

def solution(comCount, networkMatrix):
    count = 0
    visited = [False] * comCount
    for i in range(comCount):
        if visited[i] != True:
            count +=1
            bfs(networkMatrix, i, visited)
    return count

print(solution(3, [[1, 1, 0], [1, 1, 0], [0, 0, 1]]))
print(solution(3, [[1, 1, 0], [1, 1, 1], [0, 1, 1]]))
print(solution(4, 
            [[1, 1, 0, 0], 
             [1, 1, 0, 0], 
             [0, 0, 1, 1],
             [0, 0, 1, 1]]))