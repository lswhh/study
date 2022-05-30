# https://programmers.co.kr/learn/courses/30/lessons/42746

from functools import cmp_to_key

def sortFunc(x):
    lenX = len(x)
    result = x
    for i in range(4):
        if i >= lenX:
            result = result + x[lenX-1]
    result += str(4 - lenX)
    return result


def rSortFunc(x,y):
    str1 = x + y
    str2 = y + x
    if int(str1) > int(str2):
        return 1
    else:
        return -1

def solution(numbers):
    numbersStrList = list(map(str,numbers))

    numbersStrList.sort(key=cmp_to_key(rSortFunc), reverse=True)
    # numbersStrList.sort(key=sortFunc, reverse=True)
    maxNumberStr = ''.join(numbersStrList)

    resultNum = int(maxNumberStr)
    answer = str(resultNum)
    return answer

print(solution([6, 10, 2]))
print(solution([6, 9, 99, 10]))
print(solution([101, 10, 232, 23]))
print(solution([1, 10, 100, 1000]))
print(solution([9, 998]))
print(solution([3, 30, 34, 5, 9]))
	#"9534330"
print(solution([1000, 100]))
print(solution([0, 0, 0, 0, 0, 0]))
print(solution([1, 11, 111, 1111]))
print(solution([10, 101]))
print(solution([23, 233]))
