from datetime import datetime, timedelta

def solution(lines):
    time = []
    l = len(lines)
    if l == 1:
        return 1

    for i in lines:
        date = datetime.strptime(i[:23], '%Y-%m-%d %H:%M:%S.%f')
        s = float(i[24:-1])
        sec = timedelta(seconds=s - 0.001)
        start = date - sec
        time.append(start.time())
        time.append(date.time())

    print(time)

    cnt = {}
    for i in time:
        try:
            if i.microsecond <= 1000:
                t = i.second - 1
                cnt[t] += 1
            else:
                t = i.second
                cnt[t] += 1
        except:
                cnt[t] = 1

    return max(cnt.values())

# print(solution(["2016-09-15 00:00:00.000 3s"]))
# print(solution(["2016-09-15 23:59:59.999 0.001s"]))
# print(solution(["2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"]))
# print(solution(["2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"]))
print(solution(["2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s"]))
# print(solution(["2016-09-15 00:00:00.000 2.3s", "2016-09-15 23:59:59.999 0.1s"]))