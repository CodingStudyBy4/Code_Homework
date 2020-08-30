def solution(brown, yellow):
    b, a = brown + yellow
    a = yellow
    # x, y
    # b = x * y = xy
    # a = (x-2) * (y-2) = xy - 2(x+y) + 4
    # x+y = abs(a-b-4)      xy = b 이므로
    sum = abs((a-b-4)//2)
    for i in range(1, sum):
        if i * (sum-i) == b:
            return [sum-i, i]

print(solution(10, 2))
print(solution(8, 1))
print(solution(24, 24))

'''
def solution(brown, red):
    for i in range(1, int(red**(1/2))+1):
        if red % i == 0:
            if 2*(i + red//i) == brown-4:
                return [red//i+2, i+2]
'''

'''
def solution(brown, red):
    nm = brown + red
    for n in range(1, nm+1):
        if nm%n != 0:
            continue
        m = nm//n
        if (n-2)*(m-2) == red:
            return sorted([n, m], reverse = True)
'''

'''
import math
def solution(brown, yellow):
    w = ((brown+4)/2 + math.sqrt(((brown+4)/2)**2-4*(brown+yellow)))/2
    h = ((brown+4)/2 - math.sqrt(((brown+4)/2)**2-4*(brown+yellow)))/2
    return [w,h]
'''

'''
def solution(brown, yellow):
    answer = []
    n = int(brown/2 + 2)
    for i in range(n-3, int(n/2 - 1), -1):
        if (i-2)*(n-i-2) == yellow:
            return [i, n-i]
'''