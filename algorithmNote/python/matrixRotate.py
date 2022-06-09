def rotateMatrixRight90(aMatrix):
    row = len(aMatrix)
    col = len(aMatrix[0])
    result = [[0 for _ in range(col)] for _ in range(row)]

    for r in range(row):
        for c in range(col):
            result[c][row - 1 - r] = aMatrix[r][c]
    return result

aList, bList = [[0, 0, 0], [1, 0, 0], [0, 1, 1]], [[1, 1, 1], [1, 1, 0], [1, 0, 1]]
result = []

result = aList
for i in range(4):
    for j in range(len(result)):
        print(result[j])
    print('')
    result = rotateMatrixRight90(result)

result = bList
for i in range(4):
    result = rotateMatrixRight90(result)
    for j in range(len(result)):
        print(result[j])
    print('')