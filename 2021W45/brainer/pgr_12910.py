# 나누어 떨어지는 숫자 배열
# https://programmers.co.kr/learn/courses/30/lessons/12910
def solution(arr, divisor):
    answer = [i for i in sorted(arr) if i % divisor == 0]
    if answer:
        return answer
    else:
        return [-1]
