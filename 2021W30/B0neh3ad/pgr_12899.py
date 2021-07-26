'''
    124 나라의 숫자
    https://programmers.co.kr/learn/courses/30/lessons/12899?language=python3
'''
def solution(n):
    answer = ''
    digits = ('1', '2', '4')
    while n:
        answer += digits[(n-1)%3]
        n = (n-1)//3

    return answer[::-1]