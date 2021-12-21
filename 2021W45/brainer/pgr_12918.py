# 문자열 다루기 기본
# https://programmers.co.kr/learn/courses/30/lessons/12918

def solution(s):
    s_len = len(s)
    if s_len not in {4, 6}:
        return False
    try:
        int(s)
        return True
    except:
        return False
