# https://programmers.co.kr/learn/courses/30/lessons/72412

from bisect import bisect_left
from collections import defaultdict


lanIdx = 0
posIdx = 1
hisIdx = 2
soulIdx = 3
scoreIdx = 4
def isResult(data, query):
    if query[scoreIdx] <= data[scoreIdx]:
        if query[lanIdx] == data[lanIdx] or query[lanIdx] == '-':
            if query[posIdx] == data[posIdx] or query[posIdx] == '-':
                if query[hisIdx] == data[hisIdx] or query[hisIdx] == '-':
                    if query[soulIdx] == data[soulIdx] or query[soulIdx] == '-':
                        return True
    return False

langKind = ['cpp', 'java', 'python']
posKind = ['backend', 'frontend']
histKind = ['junior', 'senior']
soulfoodKind = ['chicken', 'pizza']
def getQueryExtendList(query):
    result = []
    for i in langKind:
        for j in posKind:
            for k in histKind:
                for l in soulfoodKind:
                    queryData = []
                    if query[lanIdx] == '-':
                        queryData.append(i)
                    elif query[lanIdx] == i:
                        queryData.append(i)
                    else:
                        continue
                    if query[posIdx] == '-':
                        queryData.append(j)
                    elif query[posIdx] == j:
                        queryData.append(j)
                    else: 
                        continue
                    if query[hisIdx] == '-':
                        queryData.append(k)
                    elif query[hisIdx] == k:
                        queryData.append(k)
                    else:
                        continue
                    if query[soulIdx] == '-':
                        queryData.append(l)
                    elif query[soulIdx] == l:
                        queryData.append(l)
                    else:
                        continue
                    queryData.append(query[scoreIdx])
                    result.append(queryData)
    return result
def insertDataDic(dataDic, language, position, history, soulfood, score):
    langs = ['-', language]
    poss = ['-', position]
    hists = ['-', history]
    soulfoods = ['-', soulfood]
    for i in langs:
        for j in poss:
            for k in hists:
                for l in soulfoods:
                    key = i + j + k + l
                    dataDic[key].append(int(score))
    return 
# query (language, position, history, soulfood, int(score))
def countDic(dataDic, sortInfoDic, query):
    count = 0
    # queryList = getQueryExtendList(query)
    queryKey = query[0]
    score = query[1]
    if sortInfoDic[queryKey] == False:
        dataDic[queryKey].sort()
    idx = bisect_left(dataDic[queryKey], score)
    count += len(dataDic[queryKey][idx:])
    return count

def solution(info, query):

    dataDic = defaultdict(list)
    sortInfoDic = defaultdict(lambda: False)
    for i in info:
        language, position, history, soulfood, score = i.split()
        insertDataDic(dataDic, language, position, history, soulfood, score)
    # for i in dataDic.keys():
    #     dataDic[i].sort()

    queryList = []
    for i in query:
        language, delimter1, position, delimter2, history, delimter3, soulfood, score = i.split()
        queryList.append((language + position + history + soulfood, int(score)))

    answer = []

    for i in queryList:
        answer.append(countDic(dataDic,sortInfoDic, i))
    return answer

print(solution(["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"],
               ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"])
                )