def solution(s):
    answer = 0
    
    s_list = s.split(" ")
    
    for i, i_s in enumerate(s_list):
        print(f"i: {i}, i_s: {i_s}")
        if i_s == "Z":
            answer -= int(s_list[i-1])
        else:
            answer += int(i_s)
    
    return answer

