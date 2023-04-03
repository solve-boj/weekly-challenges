def gcd(a, b):
    return a if b == 0 else gcd(b, a%b)

n = int(input())
before = 0
flag = False
m = 0

for i in range(n):
    diff, after = map(int, input().split())
    if diff > 0:
        if diff != after - before:
            flag = False
        pass
    else: # diff < 0
        
        pass

    before = after

print(m if flag else -1)