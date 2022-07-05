# 문자열 내 마음대로 정렬하기
# https://school.programmers.co.kr/learn/courses/30/lessons/12915

def solution(strings, n):
    return [sorted(strings)[s] for s in sorted(range(len(strings)), key=lambda k: [i[n] for i in sorted(strings)][k])]
