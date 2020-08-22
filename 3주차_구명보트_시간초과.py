def solution(people, limit):
    answer = 0
    people.sort()
    people.reverse()#내림차순으로 정렬
    
    while people:
        
        #일단 맨 뒤에 제일 무거운 애를 태워.
        #print(people[0])
        rest = limit - people[0]
        del people[0]
        
        #그리고 남은 애들중에서 태울 수 있는 가장 무거운 애를 태워.
        for i in range(len(people)):
            if people[i] <= rest:
                del people[i]
                break
                
        answer += 1
                
    return answer
