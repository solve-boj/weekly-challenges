def solution(n):
    a, b, c = 0, 1, 1
    for i in range(n):
        c = (a+b)%1234567
        a = b
        b = c
    return a

for i in range(100):
    print(solution(i))