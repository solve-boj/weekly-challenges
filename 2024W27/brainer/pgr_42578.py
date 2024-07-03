"""
의상
https://school.programmers.co.kr/learn/courses/30/lessons/42578
"""

"""
예를 들어 코니가 가진 옷이 아래와 같고, 
오늘 코니가 동그란 안경, 
긴 코트, 
파란색 티셔츠를 입었다면

다음날은 청바지를 추가로 
입거나 동그란 안경 대신 검정 선글라스를 
착용하거나 해야합니다.
"""

from collections import Counter


def solution(clothes):
    # 의상 종류별로 개수를 세기
    clothes_counter = Counter([cloth_type for _, cloth_type in clothes])

    # 각 종류별 선택 경우의 수 계산 (해당 종류를 입지 않는 경우 포함)
    answer = 1
    for count in clothes_counter.values():
        answer *= count + 1

    # 아무것도 입지 않는 경우 제외
    return answer - 1
