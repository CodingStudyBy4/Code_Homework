def solution(citations):
    answer = 0
    n = len(citations)
    citations.sort()
    citations.reverse()
    
    while answer < n:
        if citations[answer] <= answer:
            break
        answer += 1
    return answer