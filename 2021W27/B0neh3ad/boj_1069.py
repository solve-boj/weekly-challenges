'''
    집으로
    https://www.acmicpc.net/problem/1069
'''
x, y, d, t = map(int, input().split())
dis = (x ** 2 + y ** 2) ** .5

ans = 0
k = 0

if d > t:
    if dis <= d:
        ans = min(min(t + abs(dis - d), dis), 2*t)
    else:
        ans = (dis // d) * t
        ans += min(t, abs(dis - (dis // d) * d))
else:
    ans = dis

print(ans)
