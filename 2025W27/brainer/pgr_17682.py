def solution(dartResult):
    answer = 0
    answer_result = []
    sdt = {
        "S": 1,
        "D": 2,
        "T": 3
    }
    
    dartResult = dartResult.replace("10", "K")
    
    for i, dart in enumerate(dartResult):    
        if dart in sdt.keys():
            if dartResult[i-1] == "K":
                answer_result.append(10 ** sdt[dart])
            else:
                answer_result.append(int(dartResult[i-1]) ** sdt[dart])        
        elif dart == "*":
            if len(answer_result) > 1:
                answer_result[len(answer_result)-1] = answer_result[len(answer_result)-1] * 2
                answer_result[len(answer_result)-2] = answer_result[len(answer_result)-2] * 2
            else:
                answer_result[len(answer_result)-1] = answer_result[len(answer_result)-1] * 2
            continue
        elif dart == "#":
            answer_result[len(answer_result)-1] = answer_result[len(answer_result)-1] * (-1)
        
    print(answer_result)
    answer = sum(answer_result)
    return answer
