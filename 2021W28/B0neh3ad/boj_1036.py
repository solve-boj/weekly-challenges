'''
    36진수
    https://www.acmicpc.net/problem/1036
'''
def to_10(ch): # 36진수 한 자리를 10진수 값으로 변환
    if '0' <= ch <= '9':
        return int(ch)
    elif 'A' <= ch <= 'Z':
        return ord(ch) - 55

def to_36(n): # 10진수(0~35)를 36진수 한 자리로
    if 0 <= n < 10: # 여기 0 < n < 10으로 해서 맨 처음에 typeError 남
        return str(n)
    elif 10 <= n < 36:
        return chr(n+55)

N = int(input())
nums = []
for i in range(N):
    nums.append(input())
K = int(input())

count = []
for i in range(36):
    count.append([0, i, 0]) # Z로 바꿨을 떄 증가량, 35 - 문자값, 자릿수 값 합

for num in nums:
    for i in range(len(num)):
        count[to_10(num[-i-1])][0] += (35 - to_10(num[-i-1])) * (36 ** i)
        count[to_10(num[-i-1])][2] += 36 ** i

# 'Z로 바꿨을 경우의 증가량'을 기준으로 정렬해야 한다.
count.sort(reverse = True)

# 최대 합 계산 시에는 자릿수 값 합을 이용해야 Z까지 모두 더할 수 있다.
max_sum = 0
for i in range(36):
    max_sum += (35 if (i < K) else count[i][1]) * count[i][2]

answer = ""
while max_sum:
    answer = to_36(max_sum % 36) + answer
    max_sum //= 36

print(answer or "0")