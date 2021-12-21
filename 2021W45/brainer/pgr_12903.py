# 가운데 글자 가져오기
# https://programmers.co.kr/learn/courses/30/lessons/12903

def solution(s):
    s_len = len(s)
    if s_len %2 == 0:
        return s[(s_len // 2) -1: (s_len // 2) +1]
    else:
        return s[(s_len // 2)]