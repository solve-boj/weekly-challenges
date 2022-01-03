# 하샤드 수
# https://programmers.co.kr/learn/courses/30/lessons/12947

def solution(x):
    tmp = sum(int(i) for i in ''.join(str(x)))
    return x % tmp == 0
