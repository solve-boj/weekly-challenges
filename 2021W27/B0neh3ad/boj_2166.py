'''
    다각형의 면적
    https://www.acmicpc.net/problem/2166
'''

def cross(x1, y1, x2, y2):
    return x1*y2 - x2*y1


n = int(input())
p = []
for i in range(n):
    p.append(list(map(int, input().split())))

area = 0
for i in range(2, n):
    area += cross(p[i-1][0] - p[0][0], p[i-1][1] - p[0][1], p[i][0] - p[0][0], p[i][1] - p[0][1])

area = round(abs(area / 2), 1)
print(area)