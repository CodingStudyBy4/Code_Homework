from collections import deque

def solution(people, limit):
    answer, temp = 0, 0
    sortedPeople = sorted(people)
    dq = deque(sortedPeople)
    while dq:
        try:
            answer += 1
            if dq[0] + dq[-1] <= limit:
                dq.popleft()
            dq.pop()
        except:
            return answer
    return answer

print(solution([20, 50, 80, 50], 100))
print(solution([70, 50, 80, 50], 100))
print(solution([70, 80, 50], 100))

'''
def solution(people, limit) :
    answer = 0
    people.sort()

    a = 0
    b = len(people) - 1
    while a < b :
        if people[b] + people[a] <= limit :
            a += 1
            answer += 1
        b -= 1
    return len(people) - answer
'''