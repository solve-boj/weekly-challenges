# 로또의 최고 순위와 최저 순위
# https://github.com/solve-boj/weekly-challenges

# 1	6개 번호가 모두 일치
# 2	5개 번호가 일치
# 3	4개 번호가 일치
# 4	3개 번호가 일치
# 5	2개 번호가 일치
# 6(낙첨)	그 외


def search_rank(match_num):
    """
    input: match digit num
    retunr: rank
    """
    if match_num == 6: return 1
    elif match_num == 5: return 2
    elif match_num == 4: return 3
    elif match_num == 3: return 4
    elif match_num == 2: return 5
    else: return 6


def solution(lottos, win_nums):
    answer = []

    zero_num = lottos.count(0)

    low_rank = search_rank((len(set(lottos) & set(win_nums))))
    high_rank = search_rank((len(set(lottos) & set(win_nums))) + zero_num)

    answer.append(high_rank)
    answer.append(low_rank)
    return answer
