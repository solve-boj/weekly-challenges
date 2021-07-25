tri = [i*(i+1)//2 for i in range(1, 45)]
able = [0]*1001

for i in range(44):
    for j in range(i, 44):
        for k in range(j, 44):
            tri_sum = tri[i]+tri[j]+tri[k]
            if tri_sum <= 1000:
                able[tri_sum] = 1

T = int(input())
for i in range(T):
    print(able[int(input())])