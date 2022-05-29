from itertools import permutations

def permutation(arr, r):
    arr = sorted(arr)
    used = [0 for _ in range(len(arr))]
    result = []
    def generate(chosen, used):
        if len(chosen) == r:
            result.append(chosen[:])
            return
	
        for i in range(len(arr)):
            if not used[i]:
                chosen.append(arr[i])
                used[i] = 1
                generate(chosen, used)
                used[i] = 0
                chosen.pop()
    generate([], used)
    return result


print(permutation('ABCD', 2))
print(list(permutations('ABCD', 2)))
print(permutation([1, 2, 3, 4, 5], 3))