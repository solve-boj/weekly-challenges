def solution(lottos, win_nums):
    answer = []
    rank = 7
    for i in lottos:
        if i:
            if i in win_nums:
                rank -= 1

    answer.append(6 if (rank - lottos.count(0)) > 6 else rank - lottos.count(0))
    answer.append(6 if rank > 6 else rank)

    return answer
