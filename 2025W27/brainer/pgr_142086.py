def get_unique_s(s):
    return set(s)

def get_num_s(s):
    unique_s_num = {}
    
    unique_s = list(get_unique_s(s))
    for i, i_s in enumerate(unique_s):
        unique_s_num[i_s] = s.count(i_s)
    # print(f"unique_s_num: {unique_s_num}")
    return unique_s_num

def solution(s):
    answer = []
    uniuqe_num_s = get_num_s(s)
    
    for i, i_s in enumerate(list(s)):
        # Unique value
        if uniuqe_num_s[i_s] == 1:
            answer += [-1]
            print(f"Unique: {i_s}, -1\n")
        else:
            if ''.join(list(s)[:i]).rfind(i_s) == -1:
                answer += [-1]
                continue
                
            # print(list(reversed(list(s)[:i])).index(i_s))
                
            answer += [list(reversed(list(s)[:i])).index(i_s) + 1]
            
            
#             print(f"Not Unique: {i_s}, {''.join(list(s)[:i-1]).rfind(i_s)}")
#             print(f"Find list: {''.join(list(s)[:i])}\n")
#             # print(f"reversed uniuqe_num_s: {list(reversed(uniuqe_num_s))}")
        
        # print(f"uniuqe_num_s[{i_s}]: {uniuqe_num_s[i_s]}")
    
    return answer

