def solution(number, k):
    numberList = list(number)
    answer =''

    numberLen = len(numberList)
    result = [numberList.pop(0)]
    while numberList:
        value = numberList.pop(0)
        while len(result) > 0  and k > 0 and result[-1] < value :
            result.pop()
            k -= 1
        result.append(value)
        if k == 0:
            for i in range(len(numberList)):
                value = numberList.pop(0) 
                result.append(value)
        


    return answer.join(result)

print(solution('1924', 2))