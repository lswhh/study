
def solution(brown, yellow):
    xyline = int((brown + 4) / 2)
    answer = []
    for y in range(2, int(xyline//2)+1):
        x = xyline - y
        if (x - 2) * (y -2) == yellow:
            answer = [x, y]

    return answer

print(solution(10,2)) #10	2	[4, 3]
print(solution(8,1)) # 3, 3
print(solution(24,24))