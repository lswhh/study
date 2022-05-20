# https://programmers.co.kr/learn/courses/30/lessons/42892?language=python3
import sys
sys.setrecursionlimit(10**6)

class bnode:
    def __init__(self, x, y, V):
        self.x = x
        self.y = y
        self.V = V
        self.left = None
        self.right = None
    def toStr(self):
        return ''.join([str(self.x),' ', str(self.y), ' ', str(self.V), ' '])

class binaryTree:
    def __init__(self, rootNode):
        self.root = rootNode
        self.resultList = []
    def insert(self, node):
        temp = self.root
        isLeft = True
        while temp:
            parent = temp
            if node.x < temp.x: 
                isLeft = True
                temp = temp.left
            else :
                isLeft = False
                temp = temp.right

        if isLeft == True:
            parent.left = node
        else:
            parent.right = node
        return
    def preorder(self, node):
        if node == None:
            return
        if node == self.root:
            self.resultList = []
        self.resultList.append(node.V)
        # print(node.toStr())
        self.preorder(node.left)
        self.preorder(node.right)
        return
    def inorder(self, node):
        if node == None:
            return
        if node == self.root:
            self.resultList = []
        # print(node.toStr())
        self.inorder(node.left)
        self.resultList.append(node.V)
        self.inorder(node.right)
        return
    def postorder(self, node):
        if node == None:
            return
        if node == self.root:
            self.resultList = []
        # print(node.toStr())
        self.postorder(node.left)
        self.postorder(node.right)
        self.resultList.append(node.V)
        return

def solution(nodeinfo):
    nodelist = []
    for i in range(0, len(nodeinfo)):
        nodelist.append((nodeinfo[i][0], nodeinfo[i][1], i + 1))

    nodelist.sort(key=lambda x:(-x[1], -x[0]))
    print(nodelist)
    n1 = bnode(nodelist[0][0], nodelist[0][1], nodelist[0][2])
    btree = binaryTree(n1)
    for i in range(1,len(nodelist)):
        n = bnode(nodelist[i][0], nodelist[i][1], nodelist[i][2])
        btree.insert(n)
    answer = []
    btree.preorder(n1)
    answer.append(btree.resultList)
    btree.postorder(n1)
    answer.append(btree.resultList)
    return answer

# result = [[7,4,6,9,1,8,5,2,3],[9,6,5,8,1,4,3,2,7]]
print(solution([[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]]))
