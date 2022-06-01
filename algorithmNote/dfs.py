# DFS 함수 정의
def dfs(graph, v, visited):
    # 현재 노드를 방문 처리
    visited[v] = True
    print(v, end=' ')
    # 현재 노드와 연결된 다른 노드를 재귀적으로 방문
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

# 각 노드가 연결된 정보를 리스트 자료형으로 표현(2차원 리스트)
graph = [
  [],
  [2, 3, 8],
  [1, 7],
  [1, 4, 5],
  [3, 5],
  [3, 4],
  [7],
  [2, 6, 8],
  [1, 7]
]

# 각 노드가 방문된 정보를 리스트 자료형으로 표현(1차원 리스트)
visited = [False] * 9

# 정의된 DFS 함수 호출
dfs(graph, 1, visited)

# print('===')

# from collections import deque

# def dfs(graph, start_node):
#     ## deque 패키지 불러오기
#     visited = []
#     need_visited = deque()
    
#     ##시작 노드 설정해주기
#     need_visited.append(start_node)
    
#     ## 방문이 필요한 리스트가 아직 존재한다면
#     while need_visited:
#         ## 시작 노드를 지정하고
#         node = need_visited.pop()
 
#         ##만약 방문한 리스트에 없다면
#         if node not in visited:
 
#             ## 방문 리스트에 노드를 추가
#             visited.append(node)
#             ## 인접 노드들을 방문 예정 리스트에 추가
#             # need_visited.extend(graph[node])
#             for i in range( -1, -len(graph[node]), -1):
#                 need_visited.append(graph[node][i])
                
#     return visited

# graph = dict()
 
# graph['1'] = ['2', '3', '8']
# graph['2'] = ['1', '7']
# graph['3'] = ['1', '4', '5']
# graph['4'] = ['3', '5']
# graph['5'] = ['3','4']
# graph['6'] = ['7']
# graph['7'] = ['2', '6', '8']
# graph['8'] = ['1','7']
# print(dfs(graph, '1'))