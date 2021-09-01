'''
    N개의 최소공배수
    https://programmers.co.kr/learn/courses/30/lessons/12953?language=python3
'''
from functools import reduce

def solution(arr):
    gcd = lambda a, b: gcd(b, a%b) if b else a
    answer = reduce(lambda a, b: a*b//gcd(a, b), arr)
    return answer

'''
    세 줄 컽!
'''