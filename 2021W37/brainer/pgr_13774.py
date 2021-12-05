def solution(L, x):
    answer = [i for i, v in enumerate(L) if v == x]
    if not answer: return [-1]
    return answer