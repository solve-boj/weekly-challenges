'''
    피보나치 수 만들기
    https://programmers.co.kr/learn/courses/30/lessons/12945
'''
def solution(n):
    a, b, c = 0, 1, 1
    for i in range(n):
        c = (a+b)%1234567
        a = b
        b = c
    return a
