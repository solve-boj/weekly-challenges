# 없는 숫자 더하기
# https://programmers.co.kr/learn/courses/30/lessons/86051

def solution(numbers):
    dec_int = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    numbers = list(set(numbers))
    for i in numbers:
        dec_int.remove(i)

    return sum(dec_int)