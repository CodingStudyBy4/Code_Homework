'''
# 예제 입력 1
1
1
1 1
# 예제 입력 2
3
3 4 5
2 2
'''
from sys import stdin
input = stdin.readline

N = int(input())
A = list(map(int, input().split()))
B, C = map(int, input().split())

count, temp = 0, 0

for i in range(N):
    temp = A[i] - B
    count += 1
    if temp > 0:
        count += temp // C
        if temp % C > 0:
            count += 1

print(count)
