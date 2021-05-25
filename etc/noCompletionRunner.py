# def solution(participant, completion):
#     plen = len(participant)
#     i = 0
#     while i < plen:
#         if participant[i] in completion:
#             completion.remove(participant[i])
#             del participant[i]            
#             plen -= 1
#         else:
#             i += 1
#     answer = participant[0]
#     return answer

def solution(participant, completion):
    plen = len(participant)
    i = 0
    participantDict = dict()
    for person in participant:
        if participantDict.get(person) == None:
            participantDict[person] = 1
        else:
            participantDict[person] += 1

    for compPerson in completion:
        participantDict[compPerson] -= 1
        if participantDict[compPerson] == 0 :
            del participantDict[compPerson]
        
    result = list(participantDict.keys())
    answer = result[0]
    return answer

participant = ["leo", "kiki", "eden"]	
completion = ["eden", "kiki"]
print(solution(participant, completion))

participant = ["marina", "josipa", "nikola", "vinko", "filipa"]	
completion = ["josipa", "filipa", "marina", "nikola"]
print(solution(participant, completion))

participant = ["mislav", "stanko", "mislav", "ana", "mislav"]
completion = [ "ana", "mislav", "mislav", "mislav"]
print(solution(participant, completion))