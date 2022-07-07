# 폰켓몬
# https://school.programmers.co.kr/learn/courses/30/lessons/1845
def solution(nums):
    for i in range(len(set(nums)), -1, -1): 
        if i <= int(len(nums)/2): return i
