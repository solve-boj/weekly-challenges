def gcd(a, b):
    return a if b == 0 else gcd(b, a%b)

n = int(input())
before_acc = 0
m = 0
flag = True
max_acc = 0
for i in range(n):
    diff, after_acc = map(int, input().split())
    if diff > 0:
        if diff != after_acc - before_acc:
            flag = False
    else:
        diff *= -1

        if diff < before_acc:
            if diff != before_acc - after_acc:
                flag = False
        else:
            m = gcd(diff + after_acc - before_acc, m)
            max_acc = max(max_acc, after_acc)
    before_acc = after_acc
    # print("m:", m)

if m <= max_acc:
    flag = False

if(flag):
    print(max(m, 1))
else:
    print(-1)
