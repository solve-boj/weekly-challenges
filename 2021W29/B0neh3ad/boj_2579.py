stairs = []
memo = [0]*301

def solution(num): 
    if num < 0:
        return 0
    if memo[num]:
        return memo[num]
    if num <= 1:
        memo[num] = sum(stairs[:num+1])
        return sum(stairs[:num+1])

    ans = 0
    if num > 1:
        ans = max(solution(num-2) + stairs[num], solution(num-3) + stairs[num-1] + stairs[num])
    
    memo[num] = ans
    return ans


N = int(input())
for i in range(N):
    stairs.append(int(input()))

print(solution(N-1))