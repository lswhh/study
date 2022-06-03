def solution(X, arr, indexes):
    # Write your code here
    result = []
    arrXth = []
    arrLen = len(arr)
    for i in range(arrLen):
        if arr[i] == X:
            arrXth.append(i)
    for m in indexes:
        if len(arrXth) <= m - 1:
            result.append(-1)
        else:
            result.append(arrXth[m - 1] + 1)

    return result
print(solution(8, [1, 2, 20, 8, 8, 1, 2, 5, 8, 0], [100,2]))



# def solution(X, arr, indexes):
#     # Write your code here
#     result = []
#     arrLen = len(arr)
#     for m in indexes:
#         count = 0
#         index = 0
#         for index in range(0, arrLen):
#             if arr[index] == X:
#                 count += 1
#             if count == m:
#                 break
        
#         if count < m:
#             result.append(-1)
#         else:
#             result.append(index + 1)
#     return result