do2 = ['0']
N, M = map(int, input().split())
for i in range(N):
    temp = input()
    do2.append(temp)
for i in range(M):
    temp = input()
    try:
        print(do2[int(temp)])
    except:
        print(do2.index(temp))