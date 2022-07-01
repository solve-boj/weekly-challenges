# 신고 결과 받기
# https://programmers.co.kr/learn/courses/30/lessons/92334


def solution(id_list, report, k):
    answer = []
    
    # 위 예시에서는 2번 이상 신고당한 "frodo"와 "neo"의 게시판 이용이 정지됩니다. 이때, 각 유저별로 신고한 아이디와 정지된 아이디를 정리하면 다음과 같습니다.
    report_dict = {}    # Report dict by id
    reported_id_num = {}    # Number of reports by id
    
    for i in id_list:
        report_dict[i] = []
        reported_id_num[i] = 0
        
    
    for i in report:
        u_id, r_id = i.split(" ")   # u_id: User id, r_id: Report id
        report_dict[u_id].append(r_id)  # Append report id in user id
        report_dict[u_id] = list(set(report_dict[u_id]))


    for i in report_dict.values():
        for j in i:
            reported_id_num[j] += 1


    suspend_user = [key for key, value in reported_id_num.items() if value >= k] # Will suspend user id
    
    
    for i in id_list:
        mail_sum = 0
        for j in suspend_user:
            if j in report_dict[i]:
                mail_sum += 1
        answer.append(mail_sum)
        
    return answer
