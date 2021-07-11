def solution(name):
    cp = []
    updown = 0

    for i in range(len(name)):
        if name[i] != 'A':
            cp.append(i)
            updown += min(ord(name[i]) - ord('A'), ord('Z') - ord(name[i]) + 1)

    answer = 0
    if len(cp) > 1:
        answer = 2*len(name)
        for i in range(1, len(cp)):
            answer = min(answer, 2*cp[i-1] + len(name) - cp[i], cp[i-1] + 2*(len(name) - cp[i]))
        answer += updown
    else:
        answer = (cp[0] if len(cp) else 0) + updown
    
    return answer