from collections import deque

def check_right(start, direction):
    # 4번 톱니바퀴를 넘어갔거나 맞닿은 극이 같은 경우
    if start > 4 or gears[start-1][2] == gears[start][6]:
        return
    check_right(start + 1, -direction)  # 인접한 오른쪽 톱니바퀴 회전 가능한지 파악
    gears[start].rotate(direction)  # 현재 톱니바퀴 회전

def check_left(start, direction):
    # 1번 톱니바퀴를 넘어갔거나 맞닿은 극이 같은 경우
    if start < 1 or gears[start][2] == gears[start+1][6]:
        return
    check_left(start - 1, -direction)  # 인접한 왼쪽 톱니바퀴 회전 가능한지 파악
    gears[start].rotate(direction)  # 현재 톱니바퀴 회전

# 4개의 톱니바퀴 상태 초기화
gears = {}
for i in range(1, 5):
    gears[i] = deque(map(int, input()))

k = int(input())  # 회전 횟수
for _ in range(k):
    num, direction = map(int, input().split())  # 톱니바퀴 번호, 방향
    check_right(num+1, -direction)  # 기준 톱니바퀴의 오른쪽 회전
    check_left(num-1, -direction)  # 기준 톱니바퀴의 왼쪽 회전
    gears[num].rotate(direction)  # 기준 톱니바퀴 회전

result = 0
for i in range(4):
    result += (2 ** i) * gears[i+1][0]
print(result)

# deque.ratate(n) : n이 음수이면 왼쪽으로 회전하고 양수이면 오른쪽으로 회전
