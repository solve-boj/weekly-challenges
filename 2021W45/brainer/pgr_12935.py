# 제일 작은 수 제거하기
# https://programmers.co.kr/learn/courses/30/lessons/12935

def solution(arr):
    arr_len = len(arr)
    min_num = min(arr)

    if arr_len == 1:
        return [-1]
    arr.remove(min_num)
    return arr
