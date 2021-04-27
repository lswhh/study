
def solution(aGold, N, M):
    for j in range (1, M):
        for i in range (N):
            if i == 0:
                left_up = 0 
            else:
                left_up = aGold[i-1][j-1]
            if i == n - 1:
                left_down = 0
            else:
                left_down = aGold[i+1][j-1]
            left = aGold[i][j-1]
            aGold[i][j] = aGold[i][j] + max(left_up, left_down, left)
    result = 0
    for i in range(N):
        result = max(result, aGold[i][M-1])

    return result

n,m = 3,4
gold = [ [1,3,3,2],
         [2,1,4,1],
         [0,6,4,7] ]

print(solution(gold,n,m))
