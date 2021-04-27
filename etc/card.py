def getNum( N ,Value ):
    result = N * Value
    if N % 2 == 0:
        result = result * -1
    return result

N = int(input())
data = list (map(int, input().split()))
print ( N)
print (data)
data.sort()
print (data)
idx = int(N/2)
result = 0


# result = [0 for _ in range(N)]
# result[0] = data[0]
# for i in range(1, N):
#     result[i] = max( (getNum(i-1, data[i]) + getNum(i, result[i-1])),
#                        (getNum(i, data[i]) + getNum(i-1, result[i-1]) ) )

count = 1
# 큰 값을 홀수 번째 뽑아서 최대값 만들기
for i in range(idx, N):
    result = result + (data[i] * count)
    count = count + 2

count = 2
# 작은 값을 짝수 번째 뽑아서 구하기
for i in range(idx - 1, -1, -1):
    result = result - (data[i] * count)
    count = count + 2

print(result)

 