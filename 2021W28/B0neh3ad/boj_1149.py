'''
    RGB 타일링
    https://www.acmicpc.net/problem/1149
'''
N = int(input())
a, b, c = 0, 0, 0
for i in range(N):
    x, y, z = map(int, input().split())
    a, b, c = (min(b, c) + x), (min(a, c) + y), (min(a, b) + z)

print(min(a, b, c))