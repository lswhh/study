from itertools import combinations, permutations
from math import factorial

def permutation(arr, r):
    arr = sorted(arr)
    used = [0 for _ in range(len(arr))]
    result = []
    def generate(chosen, used):
        if len(chosen) == r:
            result.append(chosen[:])
            return
	
        for i in range(len(arr)):
            if not used[i]:
                chosen.append(arr[i])
                used[i] = 1
                generate(chosen, used)
                used[i] = 0
                chosen.pop()
    generate([], used)
    return result


print(permutation('ABCD', 2))
print("nPr = ", factorial(4)/factorial(4-2))
print('permutation = ', list(permutations('ABCD', 2)))
# 조합 ==> 경우의 수
print("nCr = ", factorial(4)/(factorial(4-2)*factorial(2)))
print('combination = ', list(combinations('ABCD',2)))
print(permutation([1, 2, 3, 4, 5], 3))


# 피보나치 ==> 더한것 
# 한 번 계산된 결과를 메모이제이션(Memoization)하기 위한 리스트 초기화
d = [0] * 100

# 피보나치 함수(Fibonacci Function)를 재귀함수로 구현 (탑다운 다이나믹 프로그래밍)
def fibo(x):
    # 종료 조건(1 혹은 2일 때 1을 반환)
    if x == 1 or x == 2:
        return 1
    # 이미 계산한 적 있는 문제라면 그대로 반환
    if d[x] != 0:
        return d[x]
    # 아직 계산하지 않은 문제라면 점화식에 따라서 피보나치 결과 반환
    d[x] = fibo(x - 1) + fibo(x - 2)
    return d[x]

print(fibo(99))
# 팩토리얼 ==> 곱한것  
n = 50
r = 50 - 2
# 순열 ==> 경우의 수
print("nPr = ", factorial(n)/factorial(n-r)) # 500개에서 498개를 뽑는 순열도 값이 커서 뽑아낼 수 없음
# 조합 ==> 경우의 수
print("nCr = ", factorial(n)/(factorial(n-r)*factorial(r)))