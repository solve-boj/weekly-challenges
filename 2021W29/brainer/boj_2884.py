# 알람 시계
# https://www.acmicpc.net/problem/2884

h, m = map(int, input().split())

total_mins = h*60+m - 45

if total_mins < 0:
    mins = m - 45
    if mins >= 0:
        print(f'23 {mins}')
    else: print(f'23 {60 + mins}')
else:
    answer_hour = total_mins // 60
    total_mins = total_mins - answer_hour*60
    print(f"{answer_hour} {total_mins}")
