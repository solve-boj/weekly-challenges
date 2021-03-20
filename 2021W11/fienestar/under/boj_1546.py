'''
    평균
    https://www.acmicpc.net/problem/1546
'''
input()
l=list(map(int,input().split()))
m=max(l)
l=list(map(lambda x:x/m*100,l))
print(sum(l)/len(l))