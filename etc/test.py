def solution(id_list, report, k):
    reporteddict = dict()
    reportedCount = dict()

    for i in report:
        space = i.find(" ")
        reporter = i[0:space]
        reportedid = i[space+1:]
        
        if reportedid in reporteddict:
            reporter_list = reporteddict[reportedid]
            if reporter_list.count(reporter) <= 0:
                reporter_list.append(reporter)
                reporteddict[reportedid] = reporter_list
        else:
            reporter_list = [reporter]
            reporteddict[reportedid] = reporter_list 
    resultdict = dict()

    for i in id_list:
        if i in reporteddict:
            if len(reporteddict[i]) >= k:
                reporter_list = reporteddict[i]
                for j in reporter_list:
                    if j in resultdict:
                        resultdict[j] += 1
                    else:
                        resultdict[j] = 1
                

    mail_count = []
    for i in id_list:
        if i in resultdict:
            mail_count.append(resultdict[i])
        else:
            mail_count.append(0)

    answer = mail_count
    return answer



print(solution(["muzi", "frodo", "apeach", "neo"],
 ["muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"], 2))
