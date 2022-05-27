def oddNumbers(l, r):
    # Write your code here
    result = []
    for i in range(l, r+1):
        if i % 2 != 0:
            result.append(i)
    return result

print(oddNumbers(1,10))