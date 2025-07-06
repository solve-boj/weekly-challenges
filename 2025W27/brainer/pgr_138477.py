def solution(k, score):
    answer = []
    result_of_days = [[] for _ in range(len(score))]
    
    for i, i_score in enumerate(score):
        # print(i_score)
        # print(result_of_days[i:])
        
        for j in range(len(score) - i):
            # print(f"i + j: {i+j}, i_score: {i_score}")
            result_of_days[i+j].append(i_score)
    
    for i in result_of_days:
        i = sorted(list(i), reverse=True)
        # print(i)
        
        if len(i) < k:
            answer.append(i[-1])
        else:
            answer.append(i[k-1])

    return answer

