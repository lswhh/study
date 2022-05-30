# https://programmers.co.kr/learn/courses/30/lessons/42579

from audioop import reverse
from collections import defaultdict
def sumPlays(playList):
    result = 0
    for i in playList:
        result += i[0]
    return result

def solution(genres, plays):
    kindDic = defaultdict(list)
    kindSumList = []
    for i in range(len(genres)):
        kindDic[genres[i]].append((plays[i], i))

    for i in kindDic.keys():
        kindDic[i].sort(key=lambda x: (-x[0], x[1]))
        kindSumList.append( (sumPlays(kindDic[i]), i) ) 
    
    kindSumList.sort(reverse = True)
    print(kindSumList)
    answer = []
    for totoalPlayCnt, kind in kindSumList:
        for i in range(2):
            try: 
                songPlayCnt, songNumber = kindDic[kind][i]
                answer.append(songNumber)
            except:
                pass
    return answer


print(solution(["classic", "pop", "classic", "classic", "pop"],	
               [500, 600, 150, 800, 2500])) #	[4, 1, 3, 0]