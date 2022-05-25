
# key, lock max = 20
def setLockInCenter(place, lock, row, col):
    for i in range(row):
        for j in range(col):
            place[row + i][col +j] = lock[i][j]
    return place

def setKey(lockOnPlace, key, keyRow, keyCol):
    row = len(key)
    col = row
    for i in range(row):
        for j in range(col):
            lockOnPlace[keyRow +i][keyCol +j] = lockOnPlace[keyRow + i][keyCol +j] + key[i][j]   
    return lockOnPlace

def isOpen(keyLockOnPlace, row, col):
    for i in range(row):
        for j in range(col):
            if keyLockOnPlace[row + i][col + j] != 1:
                return False
    return True

def rotateRight90(key):
    row = len(key)
    col = len(key[0])
    result = [[0 for _ in range(col)] for _ in range(row)]

    for r in range(row):
        for c in range(col):
            result[c][row - 1 - r] = key[r][c]
    return result

def solution(key, lock):
    row = len(lock)
    col = row
    for k in range(4):
        for i in range(col*2):
            for j in range(row*2):
                # 초기화
                place = [[0 for _ in range(col * 3)] for _ in range(row * 3)]
                # 자물쇠 설정 
                place = setLockInCenter(place, lock, row, col)
                # 키 결합
                place = setKey(place, key, j, i)
                # 열렸는지 확인
                if isOpen(place, row, col) == True:
                    return True
        key = rotateRight90(key)

    return False

print(solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]], [[1, 1, 1], [1, 1, 0], [1, 0, 1]]))