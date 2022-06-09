
# 문자열 처리, 아스키 코드
intVal = 10
strVal = str(intVal)
print(strVal) # '10'
strVal = 'a'
try :
    intVal = int(strVal) # invalid literal
except Exception as e: # invalid literal for int() with base 10: 'a'
    print(e)

intVal = ord(strVal)
print(intVal)  # 97
print(chr(intVal)) # 'a'

strList = ['a', 'b', 'c']
print(''.join(strList))
print(strList)
intList = [10, 20, 30]
try: 
    print(''.join(intList)) # sequence item 0: expected str instance, int found
except Exception as e:
    print(e)

print(list(map(str, intList)))

strA = 'A'
strB = 'B'
strAB = strA + strB
print(strAB)
strAB = "-".join([strA,strB])
print(strAB)

# 리스트 복사 정상
str1 = ['a','b', 'c']
str2 = str1[:]
str1[0] = 'D'
print(str(str1) + ':' + str(str2))

# 리스트 복사 포인터만=> 같이 바뀜
str1 = ['a','b', 'c']
str2 = str1
str1[0] = 'D'
print(str(str1) + ':' + str(str2))
