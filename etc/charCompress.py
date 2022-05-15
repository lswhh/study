
def solution(s):
    max_length = 1000
    length = len(s)
    result = length

    for unit in range(1, int(length/2) + 1):
        compressStr = ""
        compUnitStr = ""
        count = 1
        for i in range(0, length - unit + 1, unit):
            if len(compUnitStr) == 0:
                compUnitStr = s[i:i + unit]
                continue
            else:
                if compUnitStr == s[i:i + unit]:
                    count += 1
                else:
                    if count > 1:
                        compressStr += (str(count))
                    compressStr += compUnitStr
                    compUnitStr = s[i:i + unit]
                    count = 1
        if count > 1:
            compressStr += str(count)
        compressStr += (compUnitStr)
        if i + unit < length:
            compressStr += (s[i+unit:])
        
        if result > len(compressStr) :
            result = len(compressStr)

    answer = result
    return answer

print(solution('aabbaccc'))
print(solution('ababcdcdababcdcd'))

