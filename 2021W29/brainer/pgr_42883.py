# 큰 수 만들기
# https://programmers.co.kr/learn/courses/30/lessons/42883

import sys

sys.setrecursionlimit(2 ** 30)

save_number = None

def compare_last_new(num, answer, k):
    global save_number
    for i, v in enumerate(save_number[num:]):
        if answer and answer[-1] < v and k > 0:
            answer.pop(-1)
            k-=1
            answer, num, k = compare_last_new(i+num, answer, k)
            if k == 0: return answer, num, k
            
        answer.append(v)

    return answer, num, k

def solution(number, k):
    number = list(map(int, list(number)))
    answer = []

    global save_number
    save_number = number
    
    if len(set(number)) == 1:
        return ''.join(list(map(str, number[len(set(number))+1:])))

    answer, _, k = compare_last_new(0, answer, k)

    if k > 0:
        if k == 1: 
            return ''.join(list(map(str, answer[:-1])))

        return ''.join(list(map(str, answer[:k-1])))

    return ''.join(list(map(str, answer)))
