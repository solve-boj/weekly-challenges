'''
    두 수 비교하기
    https://www.acmicpc.net/problem/1330
'''
l=list(map(int,input().split()))

if l[0] > l[1]:
    print('>')
elif l[0] < l[1]:
    print('<')
else:
    print('==')