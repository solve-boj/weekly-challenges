def check(std, cmp):
    strikes = 0
    balls = 0
    for i in range(3):
        for j in range(3):
            if std[i] == cmp[j]:
                if i == j:
                    strikes += 1
                else:
                    balls += 1
    return [strikes, balls]

cand = [0]*1000

N = int(input())
for _ in range(N):
    temp = input().split()
    ques = temp[0]
    ans = list(map(int, temp[1:]))
    for i in range(1, 10):
        for j in range(1, 10):
            if j != i:
                for k in range(1, 10):
                    if k != j and k != i:
                        if ans == check(ques, str(i*100+j*10+k)):
                            cand[i*100+j*10+k] += 1

result = 0
for j in range(111, 1000):
    if cand[j] == N:
        result += 1

print(result)
