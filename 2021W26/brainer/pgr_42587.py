# https://programmers.co.kr/learn/courses/30/lessons/42587
# 프린터

import numpy as np

def calculate(priorities, location):
    prior_indexs = list(np.arange(len(priorities))) # priorities 참조용
    prior_indexs_loc_value = prior_indexs[location] # 참조용 priorities의 location index value
    answer_index = 0

    while True:
        for i in priorities:
            if max(priorities) == i:
                if prior_indexs[0] == prior_indexs_loc_value: 
                    return answer_index+1
                priorities = priorities[1:]
                prior_indexs = prior_indexs[1:]
                answer_index+=1
            else:
                priorities = priorities[1:] + [priorities[0]]
                prior_indexs = prior_indexs[1:] + [prior_indexs[0]]


def solution(priorities, location):
    answer = calculate(priorities, location)
    return answer
