#같은 숫자는 싫어
#https://school.programmers.co.kr/learn/courses/30/lessons/12906
def solution(arr):
    return [v for i, v in enumerate(arr) if i ==0 or v != arr[i-1]]
