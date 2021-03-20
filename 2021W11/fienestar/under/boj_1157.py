'''
    단어 공부
    https://www.acmicpc.net/problem/1157
'''
d = {}
m = 0
s = False
for i in input():
    i = i.upper()
    if i not in d: d[i] = 0
    d[i] += 1
    if d[i] >= m:
        s = (d[i] == m)
        m = d[i]
if s:
    print('?')
else:
    print(sorted(d.items(),key=lambda x: -x[1])[0][0])