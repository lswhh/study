class Node(object):
    def __init__(self, key, data=None):
        self.key = key
        self.data = data
        self.children = {}

class Trie:
    def __init__(self):
        self.head = Node(None)

    def insert(self, string):
        currentNode = self.head

        for char in string:
            if char not in currentNode.children:
                currentNode.children[char] = Node(char)
            currentNode = currentNode.children[char]
        currentNode.data = string

    def search(self, string):
        currentNode = self.head

        for char in string:
            if char in currentNode.children:
                currentNode = currentNode.children[char]
            else:
                return False

        if currentNode.data:
            return True
        else:
            return False

    def starts_with(self, prefix, strLen = 0):
        currentNode = self.head
        words = []

        for p in prefix:
            if p in currentNode.children:
                currentNode = currentNode.children[p]
            else:
                return []

        currentNode = [currentNode]
        nextNode = []
        while True:
            for node in currentNode:
                if node.data:
                    if len(node.data) == strLen:
                        words.append(node.data)
                nextNode.extend(list(node.children.values()))
            if len(nextNode) != 0:
                currentNode = nextNode
                nextNode = []
            else:
                break

        return words

def solution(words, queries):
    qLen = len(queries)
    answer = [0] * qLen

    words.sort()
    trie = Trie()
    reverseTrie = Trie()
    for i in words:
        trie.insert(i)
        reverseTrie.insert(i[::-1])

    for i in range(qLen):
        # print(queries[i])
        if queries[i][0] != '?':
            # print(trie.starts_with(queries[i].replace('?',''), len(queries[i])))
            answer[i] = len(trie.starts_with(queries[i].replace('?',''), len(queries[i])))
        else:
            # print(trie.starts_with(queries[i][::-1].replace('?',''), len(queries[i])))
            answer[i] = len(reverseTrie.starts_with(queries[i][::-1].replace('?',''), len(queries[i])))

    return answer

print(solution(["frodo", "front", "frost", "frozen", "frame", "kakao"], 
               ["fro??", "????o", "fr???", "fro???", "pro?"]))  # [3, 2, 4, 1, 0]

# trie = Trie()
# word_list = ["frodo", "front", "firefox", "fire"]
# for word in word_list:
#     trie.insert(word)

# print(trie.starts_with("fro"))