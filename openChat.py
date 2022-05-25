# https://programmers.co.kr/learn/courses/30/lessons/42888
def solution(record):
    dataIdxDic = {}
    resultList = []
    i = 0
    IN = 0
    OUT = 1
    for rec in record:
        try : 
            action, uid, name = rec.split()
        except: 
            action, uid = rec.split()
            idx = dataIdxDic[uid][0]
            name = resultList[idx][0]

        if action == "Enter":
            resultList.append([name, "님이 들어왔습니다."])
            if uid in dataIdxDic:
                for uidIdx in dataIdxDic[uid]:
                    resultList[uidIdx][0] = name
                dataIdxDic[uid].append(i)
            else:
                dataIdxDic[uid] = [i]
            i += 1
        elif action == "Change":
            if uid in dataIdxDic:
                for uidIdx in dataIdxDic[uid]:
                    resultList[uidIdx][0] = name
        else: # Leave : add List
            resultList.append([name, "님이 나갔습니다."])
            dataIdxDic[uid].append(i)
            i += 1

    answer = []
    for rec in resultList:
        answer.append(rec[0] + rec[1])
    return answer

print(solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"])) 
#	["Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.", "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다."]