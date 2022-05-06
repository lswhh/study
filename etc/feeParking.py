# 주차 요금 계산
# [180, 5000, 10, 600]
# ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]
# [14600, 34400, 5000]

# [120, 0, 60, 591]	["16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT","18:00 0202 OUT","23:58 3961 IN"]	[0, 591]

# [1, 461, 1, 10]	["00:00 1234 IN"]	[14841]

def calcParkingTime( inT, outT ):
    inTime= inT.split(':')[0]
    inMinute= inT.split(':')[1]
    inTimeByMinute = (int(inTime) * 60) + int(inMinute)
    outTime = outT.split(':')[0]
    outMinute= outT.split(':')[1]
    outTimeByMinute = (int(outTime) * 60) + int(outMinute)
    result = outTimeByMinute - inTimeByMinute
    return result

def solution(fees, records):
    basicTime = fees[0]
    basicFee = fees[1]
    additionalTimeUnit = fees[2]
    additionalTimeFee = fees[3]
    result = []
    carInOutParkingTimeRecords = dict() # key:carNumber, values: IN time, OUT time, Parking Total Minute

    for i in records:
        data = i.split(' ')
        carNumber = data[1]
        inOut = data[2]
        time = data[0]

        if carNumber in carInOutParkingTimeRecords:
            valueList = carInOutParkingTimeRecords[carNumber]
        else :
            valueList = [0 for i in range(3)]
            valueList[1] = "23:59"

        if inOut == "IN" :
            valueList[0] = time
        else : #OUT
            valueList[1] = time
            valueList[2] = valueList[2] + calcParkingTime(valueList[0], valueList[1])
            valueList[0] = 0
            valueList[1] = "23:59"

        carInOutParkingTimeRecords[carNumber] = valueList

    for i in carInOutParkingTimeRecords.values():
        if i[0] != 0: # 아직 나가지 않은 차량 23:59로 계산
            i[2] = i[2] + calcParkingTime(i[0], i[1])

    print(carInOutParkingTimeRecords)

    

    answer = []
    return answer

solution([120, 0, 60, 591],	["16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT","18:00 0202 OUT","23:58 3961 IN"])