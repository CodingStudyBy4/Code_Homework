def solution(citations):
    answer = [0]
    sortedCitations = sorted(citations, reverse=1)
    for i in range(len(sortedCitations)):
        if i+1 <= sortedCitations[i]:
            answer.append(i+1)
    return answer.pop()

print(solution([3, 0, 6, 1, 5]))
print(solution([12,11,10,9,8,1]))
print(solution([6,6,6,6,6,1]))

'''
def solution(citations):
    citations.sort(reverse=True)
    answer = max(map(min, enumerate(citations, start=1)))
    return answer
'''

'''
def solution(citations):
    citations = sorted(citations)
    l = len(citations)
    for i in range(l):
        if citations[i] >= l-i:
            return l-i
    return 0
'''