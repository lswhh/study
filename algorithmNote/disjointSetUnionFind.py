class Node:
    def __init__(self, id):
        self.parent = self
        self.id = id
    def isRoot(self):
        if self.parent == self:
            return True
        else:
            return False

def findParent(node):
    if node.isRoot() != True:
        node.parent = findParent(node.parent)
    return node.parent

def union(node1, node2):
    n1Parent = findParent(node1)
    n2Parent = findParent(node2)
    if n1Parent.id < n2Parent.id:
        node2.parent = node1.parent
    else:
        node1.parent = node2.parent
    return

def solution(edgeMatrix, plan):
    answer = 'YES'
    cityCount = len(edgeMatrix[0])
    idTable = dict()
    cityList = []

    for i in range(cityCount):
        n = Node(i)
        # cityList.append(n)
        idTable[n.id] = n

    for i in range(cityCount):
        for j in range(0, i + 1):
            if edgeMatrix[i][j] == 1:
                union(idTable[i], idTable[j])
    for i in range(0, len(plan) -1):
        if findParent(idTable[plan[i]]) != findParent(idTable[plan[i+1]]):
            answer = 'NO'
            break
        else:
            pass

    return answer

print(solution(
        [[0,1,0,1,1],
         [1,0,1,1,0],
         [0,1,0,0,0],
         [1,1,0,0,0],
         [1,0,0,0,0]], 
        [2,3,4,3]))
print(solution(
        [[0,1,0,1,1],
         [1,0,0,1,0],
         [0,0,0,0,0],
         [1,1,0,0,0],
         [1,0,0,0,0]], 
        [2,3,4,3]))