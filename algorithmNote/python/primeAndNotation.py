# 소수 구하기
import math

def isPrime(N):
    result = False
    print(N)
    n = N
    max = int(math.sqrt(n))
    for i in range(2, max+1):
        if (n % i) == 0:
            result = False
            break
        else:
            result = True
    if (1 < n) and (n < 4) :
        result = True
    return result
# 10진수 n -> k 진수 문자열
def changeNotationStr(n, k):
    resultStr = ''

    while n > 0:
        n, remain = divmod(n, k)
        resultStr += str(remain)
    return resultStr[::-1] 
    

# 10진수 n -> k 진수 리스트
def changeNotation(n, k):
    result = []
    while  n > 0 :
        n, remain = divmod(n, k)
        result.append(remain)

    result.reverse()
    # print(result)
    return result
# n진수 -> 10진수
print(int('101',2))
print(int('202',3))
print(int('303',4))
print(int('404',5))
print(int('505',6))
print(int('ACF',16))

print(changeNotation(45, 3))
print(changeNotationStr(45, 3))

# n진수 -> n 진수
print(changeNotationStr(int('c',16),4)) # 16진수인 C를 4진수로 바꾸는것
print(changeNotationStr(int('4',6),3))  # 6진수인 4를 3진수로 바꾸는것
print(changeNotationStr(int('21',3),7)) # 3진수인 21을 7진수로 바꾸는것
print(changeNotationStr(int('15',9),5)) # 9진수인 15를 5진수로 바꾸는것