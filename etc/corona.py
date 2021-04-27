def intersect(CoronaMan, Person):
    result = False
    pIdx = 0
    oldpIdx = 0
    if len(Person) == 0:
        result = False
    else:
        for i in range(0, len(CoronaMan), 2):
            if CoronaMan[i] < Person[pIdx] and Person[pIdx] < CoronaMan[i + 1]: # 들어온 시점이 확진자 사이에 있는가
                result = True
                return True
            elif CoronaMan[i] < Person[pIdx + 1] and Person[pIdx + 1] < CoronaMan[i + 1]:  # 나간 시점이 확진자 사이에 있는가
                result = True
                return True
            elif CoronaMan[i] < Person[pIdx] and  Person[pIdx +1] < CoronaMan[i + 1]: # 확진자가 사람을 포함하는가
                result = True
                return True
            elif Person[pIdx] < CoronaMan[i] and CoronaMan[i + 1] < Person[pIdx + 1]: # 사람이 확잔자를 포함하는가
                return True

            for j in range(pIdx, len(Person), 2):
                if CoronaMan[i + 1] < Person[j]:
                    pIdx = j
                    break

    return result

N, M = map(int, input().split())
EnterLeave = list (map(int, input().split()))
Corona = int(input())
CloseContact = []
idx = 0
People = [[] for _ in range(N +1)] #[0 for _ in range(N)]
for i in range(M):
    #if EnterLeave[i] < 0:
    idx = abs(EnterLeave[i])
    People[idx].append(i)

for i in range(N + 1):
    if i != Corona:
        if intersect(People[Corona], People[i]) == True:
            CloseContact.append(i)


# print(N, M)
# print(EnterLeave)
# print(Corona)
# print(People)
# print("result")
# print(CloseContact)

for i in range(0,len(CloseContact)):
    print(CloseContact[i], end = ' ')
