n, m = map(int, input().split())
rows = []
for i in range(n):
    rows.append(list(map(int, input().split())))

columns = []
for i in range(m):
    columns.append([0] * n)

for i in range(m):
    for j in range(n):
        columns[i][j] = rows[j][i]

area = n*m*2

for i in range(n):
    area += rows[i][0]
    for j in range(1, m):
        area += abs(rows[i][j] - rows[i][j-1])
    area += rows[i][-1]

for i in range(m):
    area += columns[i][0]
    for j in range(1, n):
        area += abs(columns[i][j] - columns[i][j-1])
    area += columns[i][-1]

print(area)

'''
오늘 배운 것
columns = [[0] * n] * m
이렇게 선언하면,
0 이상 m 미만 서로 다른 정수 i, j에 대하여
columns[i]의 원소를 변경하면 columns[j]의 원소도 변경된다
그러므로 append를 이용하자...
'''