
def solution(str):
    strlen = len(str)
    finalresults = []
    for i in range(1, 4):
        startIdx = 0
        endIdx = startIdx + i
        if endIdx >= strlen: continue
        A = str[startIdx:endIdx]
        if int(A) >= 0 and int(A) <= 255:
            for j in range(1, 4):
                startIdx = i
                endIdx = startIdx + j
                if endIdx > strlen or startIdx > strlen: continue
                B = str[startIdx:endIdx]
                if int(B) >= 0 and int(B) <= 255:
                    for k in range(1, 4):
                        startIdx = i + j 
                        endIdx = startIdx + k
                        if endIdx > strlen or startIdx > strlen: continue
                        C = str[startIdx:endIdx]
                        if int(C) >= 0 and int(C) <= 255:
                            for l in range(1, 4):
                                startIdx = i + j + k 
                                endIdx = startIdx + l
                                if endIdx > strlen or startIdx > strlen: continue
                                D = str[startIdx:endIdx]
                                if int(D) >= 0 and int(D) <= 255:
                                    result = A+B+C+D
                                    if len(result) != strlen:
                                        continue
                                    else:
                                        finalresults.append(A+"."+B+"."+C+"."+D)
                                        # print(A,".",B,".",C,".",D)
    return finalresults


str = input()
result = solution(str)                                    
print(len(result))

for i in result:
    print(i)

