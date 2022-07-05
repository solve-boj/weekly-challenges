# 약수의 합
# # https://school.programmers.co.kr/learn/courses/30/lessons/12928

def solution(n):
    division = []
    for i in range(1, n+1):
        if n == 0:
            continue
        elif n % i == 0:
            division.append(i)
    return sum(division)
