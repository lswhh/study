import math

INF = 0xFFFFFFFF # 무한을 의미하는 값으로 2 ^ 32 - 1
print(abs(-1))
if math.pow(2, 32) -1 == INF:
    print("ok")

print(math.sqrt(4)) #2.0

# 몫과 나머지 한번에 구함 < quotient, remainder>
quo, remain = divmod(18, 15)
print(str(quo) + " : " + str(remain))
print("%d : %d"%(quo, remain))
print("{0} : {1}".format(quo, remain))