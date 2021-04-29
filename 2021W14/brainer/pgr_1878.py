def solution(v):
    answer = []
    x = []
    y = []
    for i, j in v:
        x.append(i)
        y.append(j)

    for i in x:
        if 1 == x.count(i):
            answer.append(i)
            break
            
    for i in y:
        if 1 == y.count(i):
            answer.append(i)
            break

    return answer
