def solution(progresses, speeds):
    answer = []

    l = len(progresses)
    day = [0 for _ in range(l)]

    for i in range(l):
        while progresses[i] < 100:
            progresses[i] += speeds[i]
            day[i] += 1

    i = 0
    while i < l:
        count = 1
        for j in range(i+1, l):
            if day[i] >= day[j]:
                count += 1
            else:
                break
        answer.append(count)
        i += count
    return answer

print(solution([93, 30, 55], [1, 30, 5]))
print(solution([99, 1],[1, 99])) #[2]

'''
def solution(progresses, speeds):
    Q=[]
    for p, s in zip(progresses, speeds):
        if len(Q)==0 or Q[-1][0]<-((p-100)//s):
            Q.append([-((p-100)//s),1])
        else:
            Q[-1][1]+=1
    return [q[1] for q in Q]
'''
'''
def solution(progresses, speeds):
    print(progresses)
    print(speeds)
    answer = []
    time = 0
    count = 0
    while len(progresses)> 0:
        if (progresses[0] + time*speeds[0]) >= 100:
            progresses.pop(0)
            speeds.pop(0)
            count += 1
        else:
            if count > 0:
                answer.append(count)
                count = 0
            time += 1
    answer.append(count)
    return answer
'''
'''
from math import ceil

def solution(progresses, speeds):
    daysLeft = list(map(lambda x: (ceil((100 - progresses[x]) / speeds[x])), range(len(progresses))))
    count = 1
    retList = []

    for i in range(len(daysLeft)):
        try:
            if daysLeft[i] < daysLeft[i + 1]:
                retList.append(count)
                count = 1
            else:
                daysLeft[i + 1] = daysLeft[i]
                count += 1
        except IndexError:
            retList.append(count)

    return retList
'''
'''by ymkim
import operator

def solution(progresses, speeds):
    answer = []

    # 큐(progresses)에 있는 동안 반복
    while progresses:
        # 하루가 지나면 진행률에 speed 만큼 더해줌
        progresses = list(map(operator.add, progresses, speeds))
        print(progresses)

        count = 0
        # 큐의 첫번째 원소가 100보다 크면 하나씩 pop하면서 개수를 센다
        while progresses and progresses[0] >= 100:
            progresses.pop(0)
            speeds.pop(0)
            count += 1

        # count가 0보다 크면 answer에 추가
        if count > 0:
            answer.append(count)

    return answer
'''
