#     "2016-09-15 21:00:00.748 2.31s",
def getIncludeTimes(endTime, lastTime):
    ehh = hh = int(endTime[0:2])
    emm = mm = int(endTime[3:5])
    ess = ss = int(endTime[6:8])
    sss = int(endTime[9:12])
    lss = int(lastTime[0:1])
    lssStr = ''
    lssStr += lastTime[2:]
    for _ in range(3 - len(lastTime[2:])):
        lssStr += '0'
    lsss = int(lssStr)
    # print(lsss)
    if sss > lsss: # milisec
        sss = sss - lsss
    else :
        if ss > 0:
            ss -= 1
            sss = (1000 + sss) - lsss
        else :
            if mm > 0 :
                mm -= 1
                ss = 59
                sss = (1000 + sss) - lsss
            else :
                mm = 59
                hh -= 1
                ss = 59
                sss = (1000 + sss) - lsss

    if ss > lss : # second
        ss = ss - lss
    else :
        if mm > 0:
            mm -= 1
            ss = (60 + ss) - lss
        else: 
            mm = 59
            hh -= 1
            ss = (60 + ss) - lss
    result = str(hh) + ':' + str(mm) + ':' + str(ss)
    resultList = []
    # resultList.append(result)
    resultList.append(f"{hh:0>2}:{mm:0>2}:{ss:0>2}")
    if ss == ess: # 1초 내에 처리된값
        pass
    elif ((ss + 1)  % 60) == ess: # 2초 내에 처리된 값
        # resultList.append(str(ehh) + ':' + str(emm) + ':' + str(ess))
        resultList.append(f"{ehh:0>2}:{emm:0>2}:{ess:0>2}")
    else:
        if ss + 1 > 59:
            ss = 0
            if mm + 1 > 59:
                hh += 1
                mm = 0
            else:
                mm += 1
        else:
            ss += 1

        # print( f"{hh:0>2}:{mm:0>2}:{ss:0>2}")
                # "I am %s. I belong to %s department." % (name, dept))
        # resultList.append(str(hh) + ':' + str(mm) + ':' + str(ss))
        resultList.append(f"{hh:0>2}:{mm:0>2}:{ss:0>2}")
        resultList.append(f"{ehh:0>2}:{emm:0>2}:{ess:0>2}")
        # resultList.append(str(ehh) + ':' + str(emm) + ':' + str(ess))

    print(resultList)
    return resultList

def solution(lines):
    refineTime = []
    refineTimeIdx = 0
    throughputPerTime = {}

    for i in lines:
        completeTimeStartIdx = i.find(' ')
        completeTimeEndIdx = i.rfind(' ')
        resultList = getIncludeTimes(i[completeTimeStartIdx+1:completeTimeEndIdx], i[completeTimeEndIdx+1:i.find('s')])
        for j in resultList:
            if j in throughputPerTime:
                throughputPerTime[j] += 1
            else:
                throughputPerTime[j] = 1
        print( i[completeTimeStartIdx+1:completeTimeEndIdx])

    print(throughputPerTime)
    valueList = list(throughputPerTime.values())
    valueList.sort(reverse=True)
    print(valueList)
    answer = valueList[0]
    return answer

print(solution([
        "2016-09-15 21:00:00.748 2.31s",
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
print("     ")
print(solution([
"2016-09-15 01:00:04.001 2.0s",
"2016-09-15 01:00:07.000 2s"
]))

print(solution( [
"2016-09-15 01:00:04.002 2.0s",
"2016-09-15 01:00:07.000 2s"
]))

