# 약수의 개수와 덧셈
# https://school.programmers.co.kr/learn/courses/30/lessons/77884

def solution(left, right):
    answer = 0
    
    for i in range(left, right + 1):
        divisors = 0
        for j in range(1, i + 1):
            if i % j == 0:
                divisors += 1
        if divisors % 2 == 0:
            answer += i
        else:
            answer -= i
    
    return answer
