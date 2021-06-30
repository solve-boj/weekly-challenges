'''
    로또의 최고 순위와 최저 순위
    https://programmers.co.kr/learn/courses/30/lessons/77484
'''
def solution(lottos, win_nums):
    lottos = set(lottos)
    win_nums = set(win_nums)
    
    lottos.discard(0)
    
    correct_count = len(lottos & win_nums)
    may_correct_count = 6 - len(lottos)
    
    rank_of = lambda x: min(6, 7-x)
    
    return [
        rank_of(correct_count + may_correct_count),
        rank_of(correct_count)
    ]