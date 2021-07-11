'''
    소수 찾기
    https://programmers.co.kr/learn/courses/30/lessons/42839
'''
def check(num, lst):
    # 소수 여부 체크 -> +1 여부 결정
    cnt = 1 if num > 1 else 0
    for i in range(2, int(num ** .5) + 1):
        if num % i == 0:
            cnt = 0
            break

    # 재귀 진행 후 소수 개수 합치기
    for i in range(10):
        if lst[i]:
            lst[i] -= 1
            cnt += check(num * 10 + i, lst)
            lst[i] += 1

    return cnt


def solution(numbers):
    digits = []
    for i in range(10):
        digits.append(numbers.count(str(i)))

    answer = 0
    for i in range(1, 10):
        if digits[i]:
            digits[i] -= 1
            answer += check(i, digits)
            digits[i] += 1

    return answer
