'''
    좌표 정렬하기
    https://www.acmicpc.net/problem/11650
'''
N = int(input())
points = []
for i in range(N):
    points.append(list(map(int, input().split())))

points.sort()

for i in range(N):
    print(points[i][0], points[i][1])