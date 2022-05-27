
# https://programmers.co.kr/learn/courses/30/lessons/42890
from itertools import combinations

# key : key column index list
def isUniqueKey(relation, key):
    dataDic = {}
    result = True
    for i in relation:
        index = ''
        for k in key:
            index += i[k] +':'
        if index in dataDic:
            result = False
            break
        else:
            dataDic[index] = 1 # 1개
    return result

def fixMinimality(relation, candidateColumnList):
    result = []

    for i, key in enumerate(candidateColumnList):
        if len(key) == 1:
            result.append(key)
        else:
            result.append(key)
            minCheckList = list(combinations(key, len(key) - 1))
            for k in minCheckList:
                if isUniqueKey(relation, k) == False:
                    pass
                else:
                    try: 
                        result.remove(key)
                        break
                    except:
                        break
    return result

def solution(relation):
    columnCount = len(relation[0])
    columnList = []
    for i in range(columnCount):
        columnList.append(i)
    candidateColumnList = []
    candidateKeyCount = 0
    
    for i in range(1, columnCount + 1):
        cancidateKeyColumns = list(combinations(columnList, i))
        for k in cancidateKeyColumns:
            if isUniqueKey(relation, k) == True:
                if len(k) == 1:
                    columnList.remove(k[0])
                candidateColumnList.append(k)

    answer = len(fixMinimality(relation, candidateColumnList))
    return answer

print(solution([["100","ryan","music","2"],["200","apeach","math","2"],["300","tube","computer","3"],["400","con","computer","4"],["500","muzi","music","3"],["600","apeach","music","2"]]))