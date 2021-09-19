'''
    다항 함수의 적분
    https://www.acmicpc.net/problem/17214
'''
v=input().split('+')

l=[]
for x in v:
    y=x.split('-')
    if y[0] != '':
        l.append(y[0])
    l.extend(map(lambda x: '-'+x,y[1:]))

ans=[]
for x in l:
    c=x.split('x')
    l=len(c)
    i=1
    if c[0] != '':
        i=int(c[0])
    if i==0:
        continue
    i//=l
    if i==1:
        ans.append('x'*l)
    elif i==-1:
        ans.append('-'+'x'*l)
    else:
        ans.append(str(i)+'x'*l)

ans.append('W')
print('+'.join(ans).replace('+-','-'))