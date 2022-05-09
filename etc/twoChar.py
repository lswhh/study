#!/bin/python3

import math
import os
import random
import re
import sys
import copy
import itertools
from itertools import combinations

#
# Complete the 'alternate' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
# Sample Input

# STDIN       Function
# -----       --------
# 10          length of s = 10
# beabeefeab  s = 'beabeefeab'
# Sample Output

# 5
#
def counter(s):
    lenS = len(s)
    before = ''
    if lenS > 1:
        for i in s:
            if before == i:
                return 0
            before = i
        return lenS
    elif lenS == 1:
        return 1
    else:
        return 0
    
def alternate(s):
    # Write your code here
    tmp = copy.copy(s)
    noDupStr = ''.join(set(tmp))   
    data = combinations(list(noDupStr), 2)
    data = list(itertools.combinations(set(tmp), 2))
    resultlen = 0
    
    for i in data:
        str = "[^" + i[0] +"|^" + i[1] + "]"
        resultstr = re.sub(str,"", tmp)
        tmplen = counter(resultstr)
        if tmplen > resultlen:
            resultlen = tmplen
            
        
    return resultlen

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    l = int(input().strip())

    s = input()

    result = alternate(s)

    fptr.write(str(result) + '\n')

    fptr.close()
