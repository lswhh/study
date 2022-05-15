# Sherlock considers a string to be valid if all characters of the string appear the same number of times. It is also valid if he can remove just  character at  index in the string, and the remaining characters will occur the same number of times. Given a string , determine if it is valid. If so, return YES, otherwise return NO.

# Example

# This is a valid string because frequencies are .


# This is a valid string because we can remove one  and have  of each character in the remaining string.


# This string is not valid as we can only remove  occurrence of . That leaves character frequencies of .

# Function Description

# Complete the isValid function in the editor below.

# isValid has the following parameter(s):

# string s: a string
# Returns

# string: either YES or NO
# Input Format

# A single string .

# Constraints

# Each character 
# Sample Input 0

# aabbcd
# Sample Output 0

# NO
# Explanation 0

# Given , we would need to remove two characters, both c and d  aabb or a and b  abcd, to make it valid. We are limited to removing only one character, so  is invalid.

# Sample Input 1

# aabbccddeefghi
# Sample Output 1

# NO
# Explanation 1

# Frequency counts for the letters are as follows:

# {'a': 2, 'b': 2, 'c': 2, 'd': 2, 'e': 2, 'f': 1, 'g': 1, 'h': 1, 'i': 1}

# There are two ways to make the valid string:

# Remove  characters with a frequency of : .
# Remove  characters of frequency : .
# Neither of these is an option.

# Sample Input 2

# abcdefghhgfedecba
# Sample Output 2

# YES
# Explanation 2

# All characters occur twice except for  which occurs  times. We can delete one instance of  to have a valid string.


import math
import os
import random
import re
import sys

#
# Complete the 'isValid' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#
def diffCount(a, b):
    result = 0
    if a > b:
        result = a - b
    else:
        result = b - a

    return result
    
def sameCount(a, b, c):
    if a == c:
        return a
    else: 
        return b

def isValid(s):
    # Write your code here
    resultStr = 'YES'
    noDupStr = set(s)
    charDict = {}
    charCount = 0
    for i in noDupStr:
        charCount = s.count(i)
        charDict[i] = charCount
    valueList = list(charDict.values())
    valueList = sorted(valueList, reverse=True)
    equalCount = valueList[0]

    print(charDict)
    resultDict = {}
    for i in valueList:
        try: resultDict[i] += 1
        except: resultDict[i] = 1
    # resultDictList = sorted(resultDict.items(), reverse=True)
    resultDictList =sorted(resultDict.items(), key=lambda x: x[1], reverse=True)

    equalCount = resultDictList[0][0]
    removeCount = 0
    for key in charDict:
        if charDict[key] != equalCount:
            if charDict[key] == 1:
                removeCount += 1
            else:
                removeCount += diffCount(equalCount, charDict[key] )
        if removeCount > 1:
            resultStr = 'NO'
            break
        
    return resultStr
    

# if __name__ == '__main__':
#     fptr = open(os.environ['OUTPUT_PATH'], 'w')

#     s = input()

s = "aabbccddeefghi"
result = isValid(s)
print(result)

s = "aaaabbcc"
result = isValid(s)
print(result)
s = "abcdefghhgfedecba"
result = isValid(s)
print(result)
# s = 'a'
s = 'aabbcd'
result = isValid(s)
print(result)

s = "ibfdgaeadiaefgbhbdghhhbgdfgeiccbiehhfcggchgghadhdhagfbahhddgghbdehidbibaeaagaeeigffcebfbaieggabcfbiiedcabfihchdfabifahcbhagccbdfifhghcadfiadeeaheeddddiecaicbgigccageicehfdhdgafaddhffadigfhhcaedcedecafeacbdacgfgfeeibgaiffdehigebhhehiaahfidibccdcdagifgaihacihadecgifihbebffebdfbchbgigeccahgihbcbcaggebaaafgfedbfgagfediddghdgbgehhhifhgcedechahidcbchebheihaadbbbiaiccededchdagfhccfdefigfibifabeiaccghcegfbcghaefifbachebaacbhbfgfddeceababbacgffbagidebeadfihaefefegbghgddbbgddeehgfbhafbccidebgehifafgbghafacgfdccgifdcbbbidfifhdaibgigebigaedeaaiadegfefbhacgddhchgcbgcaeaieiegiffchbgbebgbehbbfcebciiagacaiechdigbgbghefcahgbhfibhedaeeiffebdiabcifgccdefabccdghehfibfiifdaicfedagahhdcbhbicdgibgcedieihcichadgchgbdcdagaihebbabhibcihicadgadfcihdheefbhffiageddhgahaidfdhhdbgciiaciegchiiebfbcbhaeagccfhbfhaddagnfieihghfbaggiffbbfbecgaiiidccdceadbbdfgigibgcgchafccdchgifdeieicbaididhfcfdedbhaadedfageigfdehgcdaecaebebebfcieaecfagfdieaefdiedbcadchabhebgehiidfcgahcdhcdhgchhiiheffiifeegcfdgbdeffhgeghdfhbfbifgidcafbfcd"
#     fptr.write(result + '\n')
result = isValid(s)
print(result)
#     fptr.close()
