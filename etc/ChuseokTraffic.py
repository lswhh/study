# def getIncludeTimes(endTime, lastTime):
#     ehh = hh = int(endTime[0:2])
#     emm = mm = int(endTime[3:5])
#     ess = ss = int(endTime[6:8])
#     sss = int(endTime[9:12])
#     lss = int(lastTime[0:1])
#     lssStr = ''
#     lssStr += lastTime[2:]
#     for _ in range(3 - len(lastTime[2:])):
#         lssStr += '0'
#     lsss = int(lssStr)
#     # print(lsss)
#     if sss > lsss: # milisec
#         sss = sss - lsss
#     else :
#         if ss > 0:
#             ss -= 1
#             sss = (1000 + sss) - lsss
#         else :
#             if mm > 0 :
#                 mm -= 1
#                 ss = 59
#                 sss = (1000 + sss) - lsss
#             else :
#                 mm = 59
#                 hh -= 1
#                 ss = 59
#                 sss = (1000 + sss) - lsss

#     if ss > lss : # second
#         ss = ss - lss
#     else :
#         if mm > 0:
#             mm -= 1
#             ss = (60 + ss) - lss
#         else: 
#             mm = 59
#             hh -= 1
#             ss = (60 + ss) - lss
#     result = str(hh) + ':' + str(mm) + ':' + str(ss)
#     resultList = []
#     # resultList.append(result)
#     resultList.append(f"{hh:0>2}:{mm:0>2}:{ss:0>2}")
#     if ss == ess: # 1초 내에 처리된값
#         pass
#     elif ((ss + 1)  % 60) == ess: # 2초 내에 처리된 값
#         # resultList.append(str(ehh) + ':' + str(emm) + ':' + str(ess))
#         resultList.append(f"{ehh:0>2}:{emm:0>2}:{ess:0>2}")
#     else:
#         if ss + 1 > 59:
#             ss = 0
#             if mm + 1 > 59:
#                 hh += 1
#                 mm = 0
#             else:
#                 mm += 1
#         else:
#             ss += 1

#         # print( f"{hh:0>2}:{mm:0>2}:{ss:0>2}")
#                 # "I am %s. I belong to %s department." % (name, dept))
#         # resultList.append(str(hh) + ':' + str(mm) + ':' + str(ss))
#         resultList.append(f"{hh:0>2}:{mm:0>2}:{ss:0>2}")
#         resultList.append(f"{ehh:0>2}:{emm:0>2}:{ess:0>2}")
#         # resultList.append(str(ehh) + ':' + str(emm) + ':' + str(ess))

#     print(resultList)
#     return resultList

# def solution(lines):
#     refineTime = []
#     refineTimeIdx = 0
#     throughputPerTime = {}

#     for i in lines:
#         completeTimeStartIdx = i.find(' ')
#         completeTimeEndIdx = i.rfind(' ')
#         resultList = getIncludeTimes(i[completeTimeStartIdx+1:completeTimeEndIdx], i[completeTimeEndIdx+1:i.find('s')])
#         for j in resultList:
#             if j in throughputPerTime:
#                 throughputPerTime[j] += 1
#             else:
#                 throughputPerTime[j] = 1
#         print( i[completeTimeStartIdx+1:completeTimeEndIdx])

#     print(throughputPerTime)
#     valueList = list(throughputPerTime.values())
#     valueList.sort(reverse=True)
#     print(valueList)
#     answer = valueList[0]
#     return answer
from unittest import result


def convertToMSec(time):
    t, m, s = map(float, time.split(':'))
    result = (t * 60 * 60) + (m * 60) + s
    return result
def convertToMSecFromLastTime(lastTime):
    result = float(lastTime.replace('s',''))

    return result 
def getStartTime(completeTime, lastTime):
    result = completeTime - (lastTime - 0.001)
    return result

# 1초 내에 겹치는지 확인
def isIntersect(log1, log2):
    result = False
    if log2[1] + 1 < log1[0]: # -s- log2 -e- -s- log1 -e-
        pass
    elif log1[1] + 1 < log2[0]: # -s- log1 -e- -s- log2 -e-
        pass
    else: #include
        result = True
    return result

def windowIntersect(start, end, log):
    if log[1] < start:
        return False
    elif log[0] > end:
        return False
    else:
        return True
    return True

def calcMaxThroughtput(logList):
    logListInt = []
    for i in logList:
        logListInt.append((int(i[0] * 1000), int(i[1] * 1000)))

    maxTime = max(logListInt, key=lambda x: x[1])
    minTime = min(logListInt, key=lambda x: x[0])
    throughtputList = []
    idx = 0

    # 1 sec => 1000
    for i in range(minTime[0], maxTime[1] - 999 + 1):
        throughtputList.append(0)
        for j in logListInt:
            if windowIntersect(i, i + 999, j ) == True:
                throughtputList[idx] += 1
        throughtputList.append(0)
        idx += 1
    if len(throughtputList) == 0 :
        result = 1
    else:
        result = max(throughtputList) -1
    return result

def solution(lines):
    result = 0
    logTimeList = []
    for i in range(0,len(lines)):
        logUnit = lines[i].split(' ')
        endTime = convertToMSec(logUnit[1])
        startTime = getStartTime(endTime, convertToMSecFromLastTime(logUnit[2]))
        logTimeList.append((startTime, endTime))
    print(logTimeList)

    intersectList = [[] for _ in range(0, 2000)]
    intersectCountList = [-1 for _ in range(0, 2000)] # 자기 자신 제외

    for i in range(0, len(logTimeList)):
        intersectCount = intersectCountList[i]
        intersectList[i].append(logTimeList[i])
        for j in range(0, len(logTimeList)):
            if isIntersect(logTimeList[i], logTimeList[j]):
                intersectCount += 1
                intersectList[i].append(logTimeList[j])
        intersectCountList[i] = intersectCount
    maxIntersect = max(intersectCountList)
    maxIntersectIdx = 0
    result = 0
    for i in range(0,2000):
        if maxIntersect == intersectCountList[i]:
            throughtput = calcMaxThroughtput(intersectList[i])
            if result < throughtput :
                result = throughtput
    print(result)
    # print(intersectList)
    # print(intersectCountList)
    # print(a, " -- ", convertToMSec(a[1]), convertToMSecFromLastTime(a[2]))
    return result
print(solution(
    [
"2016-09-15 20:59:57.421 0.351s",
"2016-09-15 20:59:58.233 1.181s",
"2016-09-15 20:59:58.299 0.8s",
"2016-09-15 20:59:58.688 1.041s",
"2016-09-15 20:59:59.591 1.412s",
"2016-09-15 21:00:00.464 1.466s",
"2016-09-15 21:00:00.741 1.581s",
"2016-09-15 21:00:00.748 2.31s",
"2016-09-15 21:00:00.966 0.381s",
"2016-09-15 21:00:02.066 2.62s"
]))

# def solution(lines):

#     #get input
#     S , E= [], [] 
#     totalLines = 0 
#     for line in lines:
#         totalLines += 1
#         type(line)
#         (d,s,t) = line.split(" ")

#        ##time to float
#         t = float(t[0:-1])
#         (hh, mm, ss) = s.split(":")
#         seconds = float(hh) * 3600 + float(mm) * 60 + float(ss)

#         E.append(seconds + 1)
#         S.append(seconds - t + 0.001)

#     #count the maxTraffic
#     S.sort()

#     curTraffic = 0
#     maxTraffic = 0
#     countE = 0
#     countS = 0
#     while((countE < totalLines) & (countS < totalLines)):
#         if(S[countS] < E[countE]):
#             curTraffic += 1
#             maxTraffic = max(maxTraffic, curTraffic)
#             countS += 1
#         else: ## it means that a line is over.
#             curTraffic -= 1
#             countE += 1

#     return maxTraffic