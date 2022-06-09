import re

print(re.findall('\d+', 'abc123def56zz'))
# ['123', '56']

# match()는 문자열의 처음부터 시작해서 작성한 패턴이 일치하는지 확인합니다.
print(re.match('a', 'ab'))
print(re.match('a', 'ab'))
print(re.match('a', 'bba'))
print(re.match('a', 'ba'))
# <re.Match object; span=(0, 1), match='a'>
# <re.Match object; span=(0, 1), match='a'>
# None
# None

print(re.search('a', 'ab'))
print(re.search('a', 'ab'))
print(re.search('a', 'bba'))
print(re.search('a', 'ba'))

# <re.Match object; span=(0, 1), match='a'>
# <re.Match object; span=(0, 1), match='a'>
# <re.Match object; span=(2, 3), match='a'>
# <re.Match object; span=(1, 2), match='a'>

print(re.findall('a', 'a'))
print(re.findall('a', 'aba'))
print(re.findall('a', 'baa'))
print(re.findall('aaa', 'aaaaa'))
print(re.findall('aaa', 'aaaaaa'))
print(re.findall('\d', '숫자123이 이렇게56 있다8'))
print(re.findall('\d+', '숫자123이 이렇게56 있다8'))


# ['a']
# ['a', 'a']
# ['a', 'a']
# ['aaa']
# ['aaa', 'aaa']
# ['1', '2', '3', '5', '6', '8']
# ['123', '56', '8']

print(re.fullmatch('a', 'a'))
print(re.fullmatch('a', 'aaa'))
print(re.fullmatch('a', 'ab'))
print(re.fullmatch('a', 'ba'))
print(re.fullmatch('a', 'baa'))


# <re.Match object; span=(0, 1), match='a'>
# None
# None
# None
# None

print(re.sub('a', 'z', 'ab'))
print(re.sub('a', 'zxc', 'ab'))
print(re.sub('a', 'z', 'aaaab'))
print(re.sub('a', 'z', 'aaaab', 1))


# zb
# zxcb
# zzzzb
# zaaab

print(re.subn('a', 'z', 'ab'))
print(re.subn('a', 'zxc', 'ab'))
print(re.subn('a', 'z', 'aaaab'))
print(re.subn('a', 'z', 'aaaab', 1))

# ('zb', 1)
# ('zxcb', 1)
# ('zzzzb', 4)
# ('zaaab', 1)

result = re.search('aa', 'baab')
print(result.group())
print(result.start())
print(result.end())
print(result.span())


# aa
# 1
# 3
# (1, 3)

c = re.compile('a')

print(c.sub('zxc', 'abcdefg'))
print(c.search('vcxdfsa'))


# zxcbcdefg
# <re.Match object; span=(6, 7), match='a'>