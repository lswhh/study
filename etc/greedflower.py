import math
import os
import random
import re
import sys

# Complete the getMinimumCost function below.
def getMinimumCost(k, c):
    total_buy_count = len(c)
    previousPurchases = [0] * k
    minCost = 0
    buy_idx = 0
    if k >= total_buy_count:
        for i in c:
            minCost += i
    else:
        c.reverse()
        for i in c:
            previousPurchases[buy_idx] += 1
            buy_idx += 1
            minCost += i
            if buy_idx >= k:
                break
        for i in c[k:]:
            minCost += ((previousPurchases[buy_idx%k] + 1) * i)
            previousPurchases[buy_idx%k] += 1
            buy_idx += 1
    return minCost

print(getMinimumCost(2, [2,5,6]))
price = "390225 426456 688267 800389 990107 439248 240638 15991 874479 568754 729927 980985 132244 488186 5037 721765 251885 28458 23710 281490 30935 897665 768945 337228 533277 959855 927447 941485 24242 684459 312855 716170 512600 608266 779912 950103 211756 665028 642996 262173 789020 932421 390745 433434 350262 463568 668809 305781 815771 550800".split(' ')
c = list(map(int, price))
print(getMinimumCost(3, c))
