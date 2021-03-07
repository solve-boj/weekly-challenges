def solution(citations):
    max_index = max(citations)

    if max_index <= 0:
        return 0

    count = 0

    while max_index > 0:
        count = 0
        for i in range(len(citations)):
            if citations[i] >= max_index:
                count+=1
        if count >= max_index:
            return max_index
        max_index-=1
    
    return 0


print(solution([3, 0, 6, 1, 5]))
# print(solution([0]))
# print(solution([22, 42]))
# print(solution([6, 5, 4, 1, 0]))