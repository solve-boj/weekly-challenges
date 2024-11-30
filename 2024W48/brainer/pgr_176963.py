# 추억 점수
# https://school.programmers.co.kr/learn/courses/30/lessons/176963


def solution(name, yearning, photo):
    answer = [0] * len(photo)

    name_year_dict = {}
    for n, y in zip(name, yearning):
        name_year_dict[n] = y

    for i, p in enumerate(photo):
        for n in name:
            answer[i] += p.count(n) * name_year_dict[n]

    return answer
