'''
    리모컨
    https://www.acmicpc.net/problem/1107
'''
ok = [True] * 10

def possible(num):
    if not num:
        return ok[0]
    while num:
        if not ok[num%10]:
            break
        num //= 10
    return (not num)

# input
N = int(input())
M = int(input())
temp = []
if M:
    temp = list(map(int, input().split()))
for button in temp:
    ok[button] = False

ans = abs(N-100)
d = 1
if N:
    d = 0
    temp = N
    while temp:
        d += 1
        temp //= 10

for i in range(d, 0, -1):
    flag = False
    for j in range((10 ** i - 1) if (i-d) else N, 10 ** (i-1) - 1, -1):
        if possible(j):
            ans = min(ans, d + abs(j-N))
            flag = True
            break
    if flag:
        break

for i in range(d, 7):
    flag = False
    for j in range((10 ** i) if (i-d) else (N+1), 10 ** (i+1)):
        if possible(j):
            ans = min(ans, d + abs(j-N))
            flag = True
            break
    if flag:
        break

print(ans)