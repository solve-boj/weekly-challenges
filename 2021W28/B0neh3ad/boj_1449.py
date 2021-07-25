N, L = map(int, input().split())
points = list(map(int, input().split()))
points.sort()
now_dis = 0
result = 1
for i in range(1, N):
    now_dis += points[i]-points[i-1]
    if now_dis + 1 > L: # 하나로 붙일 수 있는 길이보다 크면
        result += 1 # 테이프 하나 새로 붙이기
        now_dis = 0

print(result)