# 소수 찾기
# https://school.programmers.co.kr/learn/courses/30/lessons/12921

import math
def is_prime_num(n):
    if n>2 and n%2 == 0: return False
    for i in range(int(math.sqrt(n)), 1, -2):
        if n%i == 0: return False
    return True

def solution(n):
    answer = [True for _ in range(0, n)]
    for i in range(2, n):
        if answer[i-1] and is_prime_num(i):
            j = 2
            while i*j <= n:
                answer[(i*j)-1] = False
                j+=1
        else: answer[i-1] = False
    return answer.count(True)-1
