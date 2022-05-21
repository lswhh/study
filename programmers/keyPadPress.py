# https://programmers.co.kr/learn/courses/30/lessons/67256
def calcDist(x1, y1, x2, y2):
    return abs(x1- x2) + abs(y1 - y2)

def solution(numbers, hand):
    leftPos = (3,0)
    rightPos = (3,2)
    keyPad = {}
    keyPad[0] = (3, 1)
    for i in range(1,10): # *= 10, # = 11
        keyPad[i] = ( (i -1) // 3, (i + 2) % 3 )
    result = []
    for i in numbers:
        if i == 1 or i == 4 or i == 7:
            result.append('L')
            leftPos = keyPad[i]
        elif i == 3 or i == 6 or i == 9:
            result.append('R')
            rightPos = keyPad[i]
        else:
            pressKey = keyPad[i]
            leftDist = calcDist(pressKey[0], pressKey[1], leftPos[0], leftPos[1])
            rightDist = calcDist(pressKey[0], pressKey[1], rightPos[0], rightPos[1])
            if leftDist < rightDist:
                result.append('L')
                leftPos = pressKey
            elif leftDist > rightDist:
                result.append('R')
                rightPos = pressKey
            else:
                if hand == "right":
                    result.append('R')
                    rightPos = pressKey
                else:
                    result.append('L')
                    leftPos = pressKey
            
    answer = ''.join(result)
    return answer



print(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5],	"right")) #"LRLLLRLLRRL"
print(solution([7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2],	"left"))	 #"LRLLRRLLLRR"
print(solution([1, 2, 3, 4, 5, 6, 7, 8, 9, 0],	"right")) #	"LLRLLRLLRL"