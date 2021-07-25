def solution(std, obj, time):
    if (time == 994) or (std == obj):
        return time
    else:
        ans = 100000
        if 2*std <= 3*obj:
            ans = min(ans, solution(2*std, obj, time+1))
        if std < 100000:
            ans = min(ans, solution(std+1, obj, time+1))
        if std > 0:
            ans = min(ans, solution(std-1, obj, time+1))
        return ans

N, K = map(int, input().split())

result = min(abs(N-K), solution(N, K, 0))
print(result)
