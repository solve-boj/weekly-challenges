'''
    리모컨
    https://www.acmicpc.net/problem/1107
'''
ok = [True] * 10

def possible(num):
    digits = 0
    if not num:
        return (ok[0], 1)
    while num:
        if not ok[num%10]:
            break
        num //= 10
        digits += 1
    return (not num, digits)

# input
N = int(input())
M = int(input())
temp = []
if M:
    temp = list(map(int, input().split()))
for button in temp:
    ok[button] = False

ans = abs(N-100)

for cand in range(1000001):
    temp = possible(cand)
    if temp[0]:
        ans = min(ans, temp[1]+abs(cand-N))

print(ans)