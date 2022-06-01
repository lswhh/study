# https://programmers.co.kr/learn/courses/30/lessons/42860
# ▲ - 다음 알파벳
# ▼ - 이전 알파벳 (A에서 아래쪽으로 이동하면 Z로)
# ◀ - 커서를 왼쪽으로 이동 (첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)
# ▶ - 커서를 오른쪽으로 이동 (마지막 위치에서 오른쪽으로 이동하면 첫 번째 문자에 커서)


import string

def solution(name):
    cursor = 0
    ans1, ans2 = 0, 0
    answer = 0
    transList = []
    for i in range(1, len(name)):
        if translate(name[i]) > 0:
            transList.append(i)
    
    answer += translate(name[0])
    minMove = len(name)
    minMoveIdx = 0
    while transList:
        minMove = len(name)
        for i in transList:
            movei = cursorMove(cursor, i, len(name))
            if minMove > movei:
                minMoveIdx = i
                minMove = movei
        answer += cursorMove(cursor, minMoveIdx, len(name))
        cursor = minMoveIdx
        answer += translate(name[minMoveIdx])
        transList.remove(minMoveIdx)

    return answer

def translate(toChar):
    toCode = ord(toChar)
    fromCode = ord('A')
    # totalLen = len(string.ascii_uppercase)
    if toCode == fromCode:
        return 0
    else:
        # 정방향
        rightDirection = toCode - fromCode
        # 역방향
        fromCode = ord('Z')
        reverseDirection = (fromCode - toCode) + 1
        return min(rightDirection, reverseDirection)

def cursorMove(currPosition, nextPosition, length):
    if currPosition == nextPosition:
        return 0
    else:
        # 정방향
        rightDirection = 0xFFFF
        for i in range(0, length):
            if ((currPosition + i) % length) == nextPosition:
                rightDirection = i
        reverseDirection = 0xFFFF
        for i in range(0, length):
            moved = (currPosition - i)
            if moved < 0 :
                moved = length + moved # index
                if moved == nextPosition:
                    reverseDirection = i
            else:
                if moved == nextPosition:
                    reverseDirection = i
        return min(rightDirection, reverseDirection)

print(solution("JEROEN"))
print(solution("JAN"))

print(solution("BBBBAAAABA"))
