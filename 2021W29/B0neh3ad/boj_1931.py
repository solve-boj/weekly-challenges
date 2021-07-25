'''
    회의실 배정
    https://www.acmicpc.net/problem/1931
'''
from operator import itemgetter

N = int(input())
sch = []
for i in [0]*N:
    sch.append(list(map(int, input().split())))

sch.sort(key = itemgetter(1, 0))

curr_end = sch[0][1]
cnt = 1
for con in sch[1:]:
    if curr_end <= con[0]:
        curr_end = con[1]
        cnt += 1

print(cnt)