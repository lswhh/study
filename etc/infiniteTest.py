import sys
import os


args = sys.argv[1:]

if len(args) != 2:
    print("Usage: infiniteTest.py \"test command\" \"test finish condition\"")
    exit()
sCmd = args[0]
sFinishCondition = args[1]
print(sCmd)
output = ""
while True:
    stream = os.popen(sCmd)
    output = stream.read()
    print(output)
    if output.find(sFinishCondition) > 0:
        break

