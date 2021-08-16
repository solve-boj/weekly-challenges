'''
    피보나치 수 4
    https://www.acmicpc.net/problem/10826
'''
import sys

mat = [[1,1],[1,0]]
res = [[0,0],[0,0]]
temp = [[0,0],[0,0]]

def square(num):
    global mat, res, temp

    if not num: return
    if num == 1:
        for i in (0, 1):
            for j in (0, 1):
                res[i][j] = mat[i][j]
        return
    
    square(num//2)

    for i in (0, 1):
        for j in (0, 1):
            t = 0
            for k in (0, 1):
                t += res[i][k] * res[k][j]
            temp[i][j] = t
    
    if num % 2:
        for i in (0, 1):
            for j in (0, 1):
                t = 0
                for k in (0, 1):
                    t += temp[i][k] * mat[k][j]
                res[i][j] = t
    else:
        for i in (0, 1):
            for j in (0, 1):
                res[i][j] = temp[i][j]

n = int(sys.stdin.readline())
square(n)
sys.stdout.write(str(res[1][0]))