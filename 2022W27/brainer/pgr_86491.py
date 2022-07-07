# 최소직사각형
# https://school.programmers.co.kr/learn/courses/30/lessons/86491

def solution(sizes):
    return max(i[0] if i[0] >= i[1] else i[1] for i in sizes) * max(i[0] if i[1] >= i[0] else i[1] for i in sizes)
