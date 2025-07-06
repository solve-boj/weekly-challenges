def selct_n_list(num, total):
    min_num = 1
    
    for i in range(-10001, 1001):
        list_num = [j for j in range(i, num + i)]
        if sum(list_num) == total:
            return list_num

def solution(num, total):
    answer = selct_n_list(num, total)
    return answer

