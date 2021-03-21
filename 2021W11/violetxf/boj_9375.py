'''
    패션왕 신해빈
    https://www.acmicpc.net/problem/9375
'''
t=int(input())

for i in range(0,t):
    dic=dict()
    n=int(input())
    for k in range(0,n):
        str=input()
        spl=str.split(" ")
        dic.setdefault(spl[1],[]).append(spl[0])
    num=1
    for k in dic:
        num*=len(dic[k])+1
    print(num-1)
