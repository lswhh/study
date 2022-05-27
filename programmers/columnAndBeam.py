# https://programmers.co.kr/learn/courses/30/lessons/60061

BEAM = 1
COLUMN = 0

def check(answer):
    for x, y, structure in answer:
        if structure == COLUMN:
            # 기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
            if y == 0 or [x, y, BEAM] in answer or [x -1, y, BEAM] in answer or [x, y - 1, COLUMN] in answer:
                continue
            else:
                return False
        else:
            # 보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.
            if [x, y -1, COLUMN] in answer or [x + 1, y - 1, COLUMN] in answer or ([x - 1, y, BEAM] in answer and [x + 1, y, BEAM] in answer) :
                continue
            else:
                return False
    return True

def solution(n, build_frame):
    answer = []
    BUILD = 1
    REMOVE = 0
    for x, y, structure, action in build_frame:
        if action == BUILD:
            answer.append([x,y,structure])
            if check(answer) == False:
                answer.remove([x,y,structure])
        else:
            answer.remove([x,y,structure])
            if check(answer) == False:
                answer.append([x,y,structure])
    
    return sorted(answer)

print(solution(5, [[1,0,0,1],[1,1,1,1],[2,1,0,1],[2,2,1,1],[5,0,0,1],[5,1,0,1],[4,2,1,1],[3,2,1,1]])) # [[1,0,0],[1,1,1],[2,1,0],[2,2,1],[3,2,1],[4,2,1],[5,0,0],[5,1,0]]