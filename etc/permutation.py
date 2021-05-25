# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    A.sort()
    before = A[0]
    if before != 1:
        return 0
    for i in range(1, len(A)):
        if (before + 1) != A[i]:
            return 0
        before = A[i]
    return 1

A = [ 4 ]

print(solution(A))