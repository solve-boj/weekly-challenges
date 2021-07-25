'''
    나이순 정렬
    https://www.acmicpc.net/problem/10814
'''
N = int(input())
lst = []
for i in range(N):
    age, name = input().split()
    age = int(age)
    lst.append([age, i, name])

lst.sort()

for i in range(N):
    print(lst[i][0], lst[i][2])