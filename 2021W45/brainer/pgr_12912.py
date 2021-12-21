def solution(a, b):
    ab_sort = sorted([a, b])
    return sum(ab_sort[0]+i for i in range(ab_sort[1]-ab_sort[0]+1))
