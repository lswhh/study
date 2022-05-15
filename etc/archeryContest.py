import itertools;
import copy;

globalResult = []
globalMaxDiff = 0
def calcDiff(apeachInfo, lionInfo):
    result = 0
    for i in range(0,11):
        if lionInfo[i] > apeachInfo[i]:
            result += 10 - i
        else:
            if apeachInfo[i] > 0:
                result -= 10 - i
    return result

def manyLowerScoreList(list1, list2):
    for i in range(10,-1, -1):
        if list1[i] > list2[i]:
            return list1
        elif list1[i] == list2[i]:
            continue
        else : #list1< list2
            return list2
    return list1

def calcComb( remainArrow, idx, apeachInfo, lionInfo ):
    global globalResult, globalMaxDiff
    if remainArrow == 0: # 남아있는 화살이 없거나, index가 끝까지 가면 종료함.
        for i in range(idx,11): # 남아있는 화살이 없으면 나머지는 0로 설정함
            lionInfo[i] = 0 
        diffScore = calcDiff(apeachInfo, lionInfo)
        if diffScore > globalMaxDiff:
            globalResult = copy.copy(lionInfo)
            globalMaxDiff = diffScore
        elif diffScore == globalMaxDiff:
            if len(globalResult) > 0:
                globalResult = copy.copy(manyLowerScoreList(globalResult, lionInfo))

        return lionInfo
    elif idx == 11:
        lionInfo[10] = remainArrow
        diffScore = calcDiff(apeachInfo, lionInfo)
        if diffScore > globalMaxDiff:
            globalResult = copy.copy(lionInfo)
            globalMaxDiff = diffScore
        elif diffScore == globalMaxDiff:
            if len(globalResult) > 0:
                globalResult = copy.copy(manyLowerScoreList(globalResult, lionInfo))
        return lionInfo

    if remainArrow > apeachInfo[idx] :
        lionInfo[idx] = apeachInfo[idx] + 1
        calcComb( remainArrow - (apeachInfo[idx] + 1), idx + 1, apeachInfo, lionInfo)
    lionInfo[idx] = 0
    calcComb(remainArrow, idx + 1, apeachInfo, lionInfo)    

    return lionInfo
def solution(n, info):
    lionInfo = [ 0 for _ in range(0,11)]
    apeachScore = 0
    lionScore = 0
    maxScoreDiff = 0
    maxLionInfo = [ 0 for _ in range(0,11)]
    calcComb(n, 0, info, lionInfo)

    # for i in range(0,11):
    answer = globalResult
    if len(answer) == 0 :
        answer.append(-1)
    return answer

# print(solution(5, [2,1,1,1,0,0,0,0,0,0,0]))
print(solution(10, [0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3]))
print([k for k in range(11)])
# for k in range(11,11):
    # print ("test")
# print([k for k in range(11,11)])
# print(list(itertools.combinations_with_replacement([k for k in range(10 + 1)], 3)))

# n	info	result
# 5	[2,1,1,1,0,0,0,0,0,0,0]	[0,2,2,0,1,0,0,0,0,0,0]
# 1	[1,0,0,0,0,0,0,0,0,0,0]	[-1]
# 9	[0,0,1,2,0,1,1,1,1,1,1]	[1,1,2,0,1,2,2,0,0,0,0]
# 10	[0,0,0,0,0,0,0,0,3,4,3]	[1,1,1,1,1,1,1,1,0,0,2]