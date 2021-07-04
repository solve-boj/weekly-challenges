N = int(input())
cmd = list(map(int, input().split()))
status = [True] * N

pos = 0
cnt = 0
while True:
    # bomb!
    print(pos + 1, end=' ')
    status[pos] = False
    cnt += 1
    if cnt == N:
        break

    # moving
    now_cmd = cmd[pos]
    i = 0
    if now_cmd > 0:
        while i < now_cmd:
            pos = (pos + 1) % N
            if status[pos]:
                i += 1
    else:
        while i < -now_cmd:
            pos = (pos + N - 1) % N
            if status[pos]:
                i += 1
