def solution(number, k):
    s, e = 0, k+1
    answer = ''
    for h in range(len(number)-k-1):
        mchar = '0'
        midx = 0
        print("s:", s, ", e:", e)
        for i in range(s,e):
            if mchar < number[i]:
                mchar = number[i]
                midx = i
        answer += mchar
        s = midx + 1
        e = s + (k+h-midx+1) if (k+h-midx > 0) else (len(number))

    return answer

print(solution("1231234", 2))