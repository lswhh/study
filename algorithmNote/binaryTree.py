import sys
sys.setrecursionlimit(10**6)

class bnode:
    def __init__(self, key, data):
        self.key = key
        self.data = data
        self.left = None
        self.right = None

    def compare(self, rNode):
        lNode = self
        dataLen = len(lNode.key)
        for i in range(dataLen):
            if lNode.key[i] < rNode.key[i]: 
                return -1
            elif lNode.key[i] > rNode.key[i]: 
                return 1
            else:
                pass
        return 0 # 두 데이터가 같으면 0 반환

    def compareKey(self, key):
        lNode = self
        dataLen = len(lNode.key)
        for i in range(dataLen):
            if lNode.key[i] < key[i]: 
                return -1
            elif lNode.key[i] > key[i]: 
                return 1
            else:
                pass
        return 0 # 두 데이터가 같으면 0 반환        

    # 비교 순서 바꾸는 함수 정렬시 사용
    def getCompareTuple(self, seq, type='asc'):
        dataLen = len(self.key)
        t = []
        if type == 'desc':
            for i in range(dataLen):
                t.append(-self.key[seq[i]])
        else:
            for i in range(dataLen):
                t.append(self.key[seq[i]])
        return (t)

    def __repr__(self):
        return str(self.key)+":"+str(self.data)

class binaryTree:
    def __init__(self, rootNode):
        self.root = rootNode

    def insert(self, node):
        temp = self.root
        isLeft = True
        while temp:
            parent = temp
            if node.compare(temp) <= 0: 
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

    def search(self, key):
        node = self.root
        if node.key == key: 
            return node.data
        while node:
            if key == node.key:
                return node.data
            elif key < node.key:
                node = node.left
            else:
                node = node.right
        return None

    def preorder(self, node, result):
        if node == None:
            return
        if node == self.root:
            result = []
        result.append(node.data)
        self.preorder(node.left, result)
        self.preorder(node.right, result)
        return result

    def inorder(self, node, result):
        if node == None:
            return result
        if node == self.root:
            result = []
        self.inorder(node.left, result)
        result.append(node.data)
        self.inorder(node.right, result)
        return result

    def postorder(self, node, result):
        if node == None:
            return result
        if node == self.root:
            result = []
        self.postorder(node.left, result)
        self.postorder(node.right, result)
        result.append(node.data)
        return result

def solution(nodeinfo):
    nodelist = []
    for i in range(0, len(nodeinfo)):
        data = [nodeinfo[i][0], nodeinfo[i][1], i + 1]
        nodelist.append(bnode(data, i+1))

    # nodelist.sort(key=lambda x:x.getCompareTuple([1,0,2], 'desc'))
    nodelist.sort(key=lambda x:(-x.key[1],-x.key[0]))
    print(nodelist)
    n1 = nodelist[0]
    print(nodelist[0])
    btree = binaryTree(n1)
    for i in range(1,len(nodelist)):
        btree.insert(nodelist[i])
    print("search = " + str(btree.search([3,5,4])))
    answer = []
    result = []
    answer.append(btree.preorder(n1, result))
    answer.append(btree.postorder(n1, result))
    return answer

# result = [[7,4,6,9,1,8,5,2,3],[9,6,5,8,1,4,3,2,7]]
print(solution([[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]]))
