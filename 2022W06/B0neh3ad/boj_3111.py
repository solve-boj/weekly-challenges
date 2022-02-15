a = input()
t = input()
an = len(a)
s = 0
e = len(t)
while True:
    idx = t[s:e].find(a) + s
    if idx == s-1:
        break
    t = t[:idx] + t[idx+an:]
    s = max(idx-an, 0)
    e = max(idx+an, e-an)
    
    idx = t[s:e].rfind(a) + s
    if idx == s-1:
        break
    t = t[:idx] + t[idx+an:]
    s = min(idx-an, s)
    e = min(idx+an, len(t))

print(t, end='')