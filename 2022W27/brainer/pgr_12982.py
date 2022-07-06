# 예산
# https://school.programmers.co.kr/learn/courses/30/lessons/12982

def solution(d, budget):
    if sorted(d)[0] > budget: return 0
    return next(len(sorted(d)[:i]) for i in range(len(d), 0, -1) if budget >= sum(sorted(d)[:i]))
