# 자연수 뒤집어 배열로 만들기
# https://programmers.co.kr/learn/courses/30/lessons/12932

def solution(n):
    return list(reversed(list(map(int, list(str(n))))))
