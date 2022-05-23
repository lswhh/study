def unions(aList1, aList2):
    aList1.sort()
    aList2.sort()
    result = []
    l1Idx = 0
    l2Idx = 0
    l1Len = len(aList1)
    l2Len = len(aList2)
    
    while l1Idx < l1Len and l2Idx < l2Len:
        if aList1[l1Idx] == aList2[l2Idx]:
            result.append(aList1[l1Idx])
            l1Idx += 1
            l2Idx += 1
        elif aList1[l1Idx] < aList2[l2Idx]:
            result.append(aList1[l1Idx])
            l1Idx += 1
        else: # aList1[l1Idx] > aList2[l2Idx]:
            result.append(aList2[l2Idx])
            l2Idx += 1
    while l1Idx < l1Len:
        result.append(aList1[l1Idx])
        l1Idx += 1
    while l2Idx < l2Len:
        result.append(aList2[l2Idx])
        l2Idx += 1
    return result

def intersects(aList1, aList2):
    aList1.sort()
    aList2.sort()
    result = []
    l1Idx = 0
    l2Idx = 0
    l1Len = len(aList1)
    l2Len = len(aList2)
    
    while l1Idx < l1Len and l2Idx < l2Len:
        if aList1[l1Idx] == aList2[l2Idx]:
            result.append(aList1[l1Idx])
            l1Idx += 1
            l2Idx += 1
        elif aList1[l1Idx] < aList2[l2Idx]:
            l1Idx += 1
        else: # aList1[l1Idx] > aList2[l2Idx]:
            l2Idx += 1
    return result

#알파벳만 추출하여 다중 집합의 원소로 만든다. 
def alphaTrans(aStr):
    result = []
    prevChar = aStr[0]
    for i in range(1, len(aStr)):
        char = aStr[i]
        if prevChar.isalpha() and char.isalpha():
            result.append(prevChar+char)
        prevChar = char
    return result

def j(aList1, aList2):
    intersectSet = intersects(aList1, aList2)
    unionSet = unions(aList1, aList2)

    if len(intersectSet) == 0 and len(unionSet) == 0:
        return 1
    result = float(len(intersectSet)) / float(len(unionSet))
    return result

def solution(str1, str2):
    
    answer = j(alphaTrans(str1.upper()), alphaTrans(str2.upper()))
    answer = int(answer * 65536)
    return answer

print(solution("handshake", "shake hands")) #	65536
print(solution("aa1+aa2", "AAAA12")) #	43690
print(solution("FRANCE","french"))
print(solution("E=M*C^2", "e=m*c^2")) #	65536