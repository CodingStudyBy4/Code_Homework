def solution(lines):
    answer = 0
    time_list = []
    print(lines)
    
    for line in lines:
        l=line.split() #띄어쓰기로 일단 split
        # l[0] : '2016-09-15'
        # l[1] : 'hh:mm:ss.000'
        # l[2] : '0.000s'
        
        t=l[1].split(":") # 콜론으로 split
        # t[0] : hh
        # t[1] : mm
        # t[2] : ss.000
        
        s = float(t[0])*3600+float(t[1])*60+float(t[2]) #end time
        t = float(l[2].split('s')[0])
        
        #print("{}  {}".format(s, t))
        time_list.append([s-t+0.001, s])
        # time_list에 각각의 시작시간과 종료시간 저장
        
    for i in range(len(time_list)):
        
        # cnt 초기화
        cnt = 1
        
        for j in range(i+1, len(time_list)):
            if time_list[i][1] + 1 > time_list[j][0]:
                cnt += 1
        
        # 최댓값 찾기
        if answer < cnt:
            answer = cnt
    return answer
