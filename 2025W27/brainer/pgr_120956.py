from itertools import permutations

def solution(babbling):
    answer = 0
    allow_bables = ["aya", "ye", "woo", "ma"]
    all_combs = []
    
    for i in range(1, len(allow_bables)+1):
        all_combs.extend(list(permutations(allow_bables, i)))
    
    all_combs = [''.join(i) for i in all_combs]
    
    for i in babbling:
        if i in all_combs:
            answer += 1
    
    return answer

