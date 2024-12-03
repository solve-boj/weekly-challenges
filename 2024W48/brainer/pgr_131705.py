# 삼총사
# https://school.programmers.co.kr/learn/courses/30/lessons/131705

import itertools

def solution(number):
    return len([n for n in itertools.combinations(number, 3) if sum(n) == 0])
