# 아래와 같이 sort function을 기존 function 유형으로 만들수 있음
from functools import cmp_to_key

def rSortFunc(x,y):
    if x > y:
        return 1
    elif x < y:
        return -1
    else: # ==
        return 0

def solution(numbers):
    numbers.sort(key=cmp_to_key(rSortFunc), reverse=True)
    print(numbers) # [99, 39, 10, 4, 3]
    numbers.sort(key=cmp_to_key(rSortFunc))
    print(numbers) # [3, 4, 10, 39, 99]
    return numbers

print(solution([3,10, 39, 4, 99]))