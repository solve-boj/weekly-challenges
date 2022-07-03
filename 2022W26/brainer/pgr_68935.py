# 3진법 뒤집기
# https://programmers.co.kr/learn/courses/30/lessons/68935

def digit_to_thrid(n):
    third = []
    
    while n > 0: 
        third.append(str(n % 3))
        n = n // 3
    return ''.join(third)

def solution(n):
    third = digit_to_thrid(n)
    answer = int(third, 3)
    return answer
