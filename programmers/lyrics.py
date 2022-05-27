from bisect import bisect_left, bisect_right

def binaryCount(base, min, max):
    return bisect_right(base, max) - bisect_left(base, min)
    
def solution(words, queries):
    qLen = len(queries)
    answer = [0] * qLen

    wordsByLen = [[] for _ in range(10001)]
    reverseWordByLen = [[] for _ in range(10001)]
    reverseWords = []
    words.sort()
    for i in words:
        wordsByLen[len(i)].append(i)
        reverseWords.append(i[::-1])

    reverseWords.sort()    
    for i in reverseWords:
        reverseWordByLen[len(i)].append(i)

    wLen = len(words)
    for i in range(qLen):
        qStr = queries[i]
        qStrLen = len(queries[i])
        count = 0
        if qStr[0] != '?':
            count = binaryCount(wordsByLen[qStrLen], qStr.replace('?','a'), qStr.replace('?','z'))
        else:
            count = binaryCount(reverseWordByLen[qStrLen], qStr[::-1].replace('?','a'), qStr[::-1].replace('?','z'))

        answer[i] = count

    return answer

print(solution(["frodo", "front", "frost", "frozen", "frame", "kakao"], 
               ["fro??", "????o", "fr???", "fro???", "pro?"]))  # [3, 2, 4, 1, 0]


def binarySearch(aList, aSearchData):
    start = 0
    end = len(aList) - 1
    mid = start
    while start <= end:
        mid = (start + end) // 2
        if aList[mid] == aSearchData:
            return mid
        elif aList[mid] > aSearchData:
            end = mid - 1
        else: # aList[mid] < aSearchData:
            start = mid + 1
    return -1
    
def isMatch(regex, strTarget):
    reLen = len(regex) 
    strLen = len(strTarget)
    if reLen != strLen:
        return False
    else:
        for i in range(reLen):
            if regex[i] == '?':
                continue
            else:
                if regex[i] == strTarget[i]:
                    pass
                else:
                    return False
    return True