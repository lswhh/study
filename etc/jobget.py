n = int(input())

incomeidx = 2
startidx = 0
jobenddict = dict()
dp = [0] * 200
for _ in range(n):
    start, time, income = map(int, input().strip().split(' ')) 
    jobenddict[start + time] = [start, time, income]
sorted(jobenddict)
jobendtime = jobenddict.keys()
max_time = max(jobenddict)

not_do_this_job = 0
do_this_job_earn = 0
dojob = []
for i in range(1, max_time + 1):
    if i in jobenddict:
        current_job_end_time = i 
        current_job_start_time = jobenddict[i][startidx]
        if current_job_end_time - 1 >= 0 and current_job_end_time - 1 <= len(dp) :
            not_do_this_job= dp[current_job_end_time-1] 
        else:
            not_do_this_job = 0
        if current_job_start_time - 1 >= 0 and current_job_start_time - 1 <= len(dp) :
            do_this_job_earn = jobenddict[i][incomeidx] + dp[current_job_start_time - 1]
        else:
            do_this_job_earn = 0
        max_income = max(not_do_this_job, do_this_job_earn)
        if do_this_job_earn > not_do_this_job:
            dojob.append([jobenddict[i][0], jobenddict[i][1]])
        dp[i] = max_income
    else:
        dp[i] = dp[i - 1]

print(dp[max_time])
for i in range(len(dojob)):
    print(dojob[i][0], end=" ")
    print(dojob[i][1])

