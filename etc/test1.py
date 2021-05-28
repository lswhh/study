from itertools import product
# a, b = map(int, input().strip().split(' '))
delimiterList = list(input())
chaList = list(input())
delimiterListLen = len(delimiterList)
combDelimiterList = list(product(delimiterList,delimiterList))
print(len(combDelimiterList))
i = 0
for combDelimiterItem in combDelimiterList:
    for i in range(0, len(combDelimiterItem)):
        print(chaList[i], end="")
        print(combDelimiterItem[i], end="")
    print(chaList[i+1])