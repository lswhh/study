from bisect import bisect_right

def solution(teamK, teamB):
    # Write your code here
    result = []
    sortedTeamK = teamK[:]
    sortedTeamK.sort()
    for check in teamB:
        result.append(bisect_right(sortedTeamK, check))
    return result

print(solution([1,4,2,4], [3,5]))
