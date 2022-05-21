def solution(s):
    table ={}
    table['zero' ] = 0
    table['one'  ] = 1
    table['two'  ] = 2
    table['three'] = 3
    table['four' ] = 4
    table['five' ] = 5
    table['six'  ] = 6
    table['seven'] = 7
    table['eight'] = 8
    table['nine' ] = 9
    strList = list(s)
    resultList = []
    startIdx = -1
    endIdx = -1
    num = -1
    for i in range(0, len(strList)):
        try :
            num = int(strList[i])
        except:
            if startIdx == -1:
                startIdx = i
            else :
                endIdx = i
            if startIdx != -1 and endIdx != -1:
                if s[startIdx:endIdx+1] in table:
                    resultList.append(table[s[startIdx:endIdx+1]])
                    startIdx = -1
                    endIdx = -1

        if num != -1:
            resultList.append(num)
            num = -1
        
    answer = ''.join(str(s) for s in resultList)
    return int(answer)

print(solution("one4seveneight"))


# def solution(s):
#     d = {'zero':0, 'one':1, 'two':2, 'three':3, 'four':4, 'five':5, 'six':6, 'seven':7, 'eight':8, 'nine':9}
#     for k in d:
#         s = s.replace(k, str(d[k]))

#     try:
#         return int(s)
#     except:
#         return 0

# s	result
# "one4seveneight"	1478
# "23four5six7"	234567
# "2three45sixseven"	234567
# "123"	123