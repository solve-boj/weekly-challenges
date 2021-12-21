# 두 개 뽑아서 더하기
# https://programmers.co.kr/learn/courses/30/lessons/68644

def solution(numbers):
    answer = []
    numbers = sorted(numbers)
    for i, v in enumerate(numbers):
        tmp = numbers.copy()
        tmp.pop(i)
        for j in tmp:
            answer.append(v+j)
    return sorted(list(set(answer)))
