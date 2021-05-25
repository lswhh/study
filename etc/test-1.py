from itertools import combinations

def solution(clothes):
    answer = 0
    count = len(clothes)
    print(count)
    kind = []
    kindCount = [0] * 100
    for i in range(0, count):
        if clothes[i][1] in kind:
            kindCount[kind.index(clothes[i][1])] += 1
        else:
            kindCount[len(kind)] += 1
            kind.append(clothes[i][1])
    lastCount = len(kind)
    result = 1
    for i in range(0, lastCount):
        result *= (kindCount[i] + 1)
    answer = result - 1
    # intermediate_value = 0
    # for i in range(1, lastCount + 1):
    #     com = combinations(kind, i)
    #     comblist = list(com)
    #     print(comblist)
    #     intermediate_value += len(comblist)
    # for i in range(0, lastCount):
    #     intermediate_value *= kindCount[i]

    print(kind)
    print(kindCount)
    return answer

# def solution(clothes):
#     from collections import Counter
#     from functools import reduce
#     cnt = Counter([kind for name, kind in clothes])
#     answer = reduce(lambda x, y: x*(y+1), cnt.values(), 1) - 1
#     return answer

# def solution(clothes):
#     clothes_type = {}

#     for c, t in clothes:
#         if t not in clothes_type:
#             clothes_type[t] = 2
#         else:
#             clothes_type[t] += 1

#     cnt = 1
#     for num in clothes_type.values():
#         cnt *= num

#     return cnt - 1

#clothes = [["yellowhat", "headgear"], ["bluesunglasses", "eyewear"], ["green_turban", "headgear"]]
clothes = [["crowmask", "face"], ["bluesunglasses", "face"], ["smoky_makeup", "face"]]
print(solution(clothes))