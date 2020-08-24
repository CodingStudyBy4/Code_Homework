def solution(brown, yellow):
    answer = []
    n = brown//2-2 #조합을 찾기 위한 정수 n
    #brown : 10 -> 10/2-2=3 -> (2, 1) : 가능한 가로, 세로 조합의 종류
    #brown : 8 -> 8/2-2=2 -> (1, 1) : 가능한 가로, 세로 조합의 종류
    #brown : 24 -> 24/2-2=10 -> (9, 1), (8, 2), (7, 3), (6, 4), (5, 5)
    
    #print(n)
    
    for i in range(1, n//2+1):# n이 10이라면 1~5
        w = n - i
        h = i
        if w * h == yellow:
            answer.append(w + 2)
            answer.append(h + 2)
            break
    
    return answer
