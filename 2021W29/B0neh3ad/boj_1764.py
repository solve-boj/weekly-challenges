'''
    듣보잡
    https://www.acmicpc.net/problem/1764
'''
N, M = map(int, input().split())
L = set()
for i in range(N):
    L.add(input())
S = set()
for i in range(M):
    S.add(input())

L.intersection_update(S)
result = list(L)
result.sort()
print(len(result))
for name in result:
    print(name)