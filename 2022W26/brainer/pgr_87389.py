# 나머지가 1이 되는 수 찾기
# https://school.programmers.co.kr/learn/courses/30/lessons/87389

def solution(n):
    return [i for i in range(1, n+1) if n % i == 1][0]
