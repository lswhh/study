from collections import deque
import copy

# https://programmers.co.kr/learn/courses/30/lessons/81302

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
maxRow = 5
maxCol = 5

def getWaitRoomArray(placeList, twoDimensionArray):
    idx = 0
    for i in placeList:
        for j in range(0, len(i)):
            twoDimensionArray[idx][j] = i[j]
        idx += 1
    return twoDimensionArray

def manhattan(x1,y1, x2,y2):
    x = 0
    y = 0
    if x1 > x2:
        x = x1 - x2
    else:
        x = x2 - x1
    if y1 > y2:
        y = y1 - y2
    else:
        y = y2 - y1
    return x + y

def wall(orgx, orgy, nx, ny, room):
    result = False
    x = 0
    y = 0
    if nx != orgx and ny == orgy:
        if nx > orgx:
            x = nx - 1
        else :
            x = orgx - 1
        y = orgy
        if room[y][x] == 'X':
            result = True
    if nx == orgx and ny != orgy:
        if ny > orgy:
            y = ny - 1
        else:
            y = orgy - 1
        x = orgx
        if room[y][x] == 'X':
            result = True
    return result

def bfs(x,y, room):
    queue = deque()
    orgx = x
    orgy = y
    queue.append((x,y))
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= maxCol or ny < 0 or ny >= maxRow:
                continue
            if room[ny][nx] == 'X' or room[ny][nx] == 'Y':
                continue
            if nx == orgx and ny == orgy:
                continue
            if room[ny][nx] == 'O':
                queue.append((nx,ny))
                room[ny][nx] = 'Y'
            if room[ny][nx] == 'P':
                if manhattan(orgx,orgy, nx, ny) <= 2 :
                    if wall(orgx, orgy, nx, ny, room) != True:
                        return 0
    return 1

def solution(places):
    waitRoom = [['O' for _ in range(5)] for _ in range(5)]
    result = [1] * 5
    for i in range(len(places)):
        tmpWaitRoom = copy.deepcopy(getWaitRoomArray(places[i], waitRoom))
        for x in range(maxCol):
            for y in range(maxRow):
                if waitRoom[y][x] == 'P':
                    waitRoom[y][x] = 'X'
                    tmpWaitRoom2 = copy.deepcopy(tmpWaitRoom)
                    result[i] = bfs(x,y,tmpWaitRoom2)
                if result[i] == 0:
                    break
            if result[i] == 0:
                break

    answer = result
    return answer

# [1, 0, 1, 1, 1] ; 마지막 테스트 케이스 틀림
print(solution([["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]))