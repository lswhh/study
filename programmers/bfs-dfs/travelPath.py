# https://programmers.co.kr/learn/courses/30/lessons/43164
from collections import defaultdict
import copy

resultList= []
def useTicket(remainTickets, idx, travel):
    global resultList
    remainResult = copy.copy(remainTickets)
    travelResult = copy.copy(travel)
    travelResult.append(remainResult[idx])
    del remainResult[idx]
    if len(remainResult) == 0:
        resultList.append(travelResult)
    return remainResult, travelResult

def dfs(currentLocation, remainTickets, result):
    canMove = False
    # 더 이상 갈 곳이 없으면 종료
    for i in remainTickets:
        if currentLocation == i[0]:
            canMove = True
        else:
            pass
    if canMove != True:
        return
    # 남은 티켓이 없는 경우 종료
    if len(remainTickets) <= 0:
        return

    for ticketIdx in range(len(remainTickets)):
        ticket = remainTickets[ticketIdx]
        if ticket[0] == currentLocation:
            remain, travel = useTicket(remainTickets, ticketIdx, result)
            dfs( ticket[1], remain, travel)

def solution(tickets):
    ticketDict = defaultdict(list)
    for i in tickets:
        ticketDict[i[0]].append([i[0], i[1], False]) # ticket: [출발, 도착 , 사용 유무]
    for i in tickets:
        ticketDict[i[0]].sort(key=lambda x : x[1])
    global resultList
    totalResultList = []
    tickets.sort(key=lambda x : x[1])
    for icnTicket in ticketDict["ICN"]:
        result = []
        dfs("ICN", copy.copy(tickets),result)
    answer = []        
    answer.append('ICN')
    for i in resultList[0]:
        answer.append(i[1])

    return answer

print(solution([["ICN", "AOO"], ["AOO", "BOO"], ["BOO", "COO"], ["COO", "DOO"], ["DOO", "EOO"], ["EOO", "DOO"], ["DOO", "COO"], ["COO", "BOO"], ["BOO", "AOO"]]))
resultList = []
print(solution([["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]))

