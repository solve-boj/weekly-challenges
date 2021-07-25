N = int(input())
te, tx = [], []
for i in range(N):
    temp = list(map(int, input().split()))
    te.append(temp[0])
    tx.append(temp[1])

te.sort()
tx.sort()

max_e, max_x, max_cnt = te[0], te[0], 1
if N > 1:
    curr = 1
    time = 0
    e_p, x_p = 1, 0
    for _ in range(2*N-1):
        if x_p >= N and e_p >= N:
            break

        if max_cnt == curr:
            if (x_p >= N) or (e_p < N and te[e_p] < tx[x_p]) : # e_p를 증가시키는 경우
                time = te[e_p]
                e_p += 1
                curr += 1
                max_s = max_e = time
                max_cnt = curr
            elif (e_p >= N) or (x_p < N and te[e_p] > tx[x_p]): # x_p를 증가시키는 경우
                if time == max_x:
                    max_x = tx[x_p]
                time = tx[x_p]
                x_p += 1
                curr -= 1
            else: # e_p < N, x_p < N, te[e_p] == tx[x_p]
                time = tx[x_p]
                e_p += 1
                x_p += 1
                max_x = tx[x_p]
        else:
            if (x_p >= N) or (e_p < N and te[e_p] < tx[x_p]): # e_p를 증가시키는 경우
                time = te[e_p]
                e_p += 1
                curr += 1
            elif (e_p >= N) or (x_p < N and te[e_p] > tx[x_p]): # x_p를 증가시키는 경우
                time = tx[x_p]
                x_p += 1
                curr -= 1
            else: # e_p < N, x_p < N, te[e_p] == tx[x_p]
                time = tx[x_p]
                e_p += 1
                x_p += 1
        # print("curr:", curr, "e_p:", e_p, "x_p:", x_p)
        # print("max_e:", max_e, "max_x:", max_x, "max_cnt:", max_cnt)

print(max_cnt)
print(max_e, max_x)