'''
    CCW
    https://www.acmicpc.net/problem/11758
'''

def cross(x1, y1, x2, y2):
    return x1*y2 - x2*y1

p = []
for i in range(3):
    p.append(list(map(int, input().split())))

det = cross(p[1][0] - p[0][0], p[1][1] - p[0][1], p[2][0] - p[0][0], p[2][1] - p[0][1])
print(det if not det else det // abs(det))