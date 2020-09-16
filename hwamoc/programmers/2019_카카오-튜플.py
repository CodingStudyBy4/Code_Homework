def solution(s):
    se = s[2:-2].split("},{")

    tp = []
    for i in se:
        tp.append(list(map(int, i.split(","))))
    tp.sort(key=len)

    ans = tp[0]
    for i in range(len(tp)-1):
        ans += [x for x in tp[i+1] if x not in tp[i]]

    return ans

print(solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"))
print(solution("{{1,2,3},{2,1},{1,2,4,3},{2}}"))
print(solution("{{20,111},{111}}"))
print(solution("{{123}}"))
print(solution("{{4,2,3},{3},{2,3,4,1},{2,3}}"))