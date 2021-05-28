from collections import Counter
def find_parent(parent, x):
    if x in parent: 
        # 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
        if parent[x] != x:
            return find_parent(parent, parent[x])
        else:
            return x
    else:
        # 부모 테이블상에서, 부모를 자기 자신으로 초기화
        parent[x] = x
        return x

# 두 원소가 속한 집합을 합치기
def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

e = int(input())
v = 100001

parent = dict()

for i in range(e):
    a, b = map(int, input().split())
    union_parent(parent, a, b)

for i in parent.keys():
    p = find_parent(parent,i)
    if parent[i] != p:
        parent[i] = p

print(len(Counter(list(parent.values()))))


print(list(parent.values()))

