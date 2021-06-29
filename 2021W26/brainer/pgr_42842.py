# https://programmers.co.kr/learn/courses/30/lessons/42842
# 카펫

def calculate(result_num, brown, yellow):
    for i in range(brown):
        for j in range(brown):
            if i * j == result_num:
                if i >= j:
                    if (i-2)*(j-2) == yellow:
                        return i, j

def solution(brown, yellow):
    answer = []
    result_num = brown + yellow
    x, y = calculate(result_num, brown, yellow)

    answer.append(x)
    answer.append(y)

    return answer
