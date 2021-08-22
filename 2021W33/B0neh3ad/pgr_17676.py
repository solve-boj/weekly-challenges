'''
    추석 트래픽
    https://programmers.co.kr/learn/courses/30/lessons/17676
'''
def data_to_seconds(time_data):
    res = 0
    res += time_data[0] * 3600000
    res += time_data[1] * 60000
    res += time_data[2] * 1000
    res += time_data[3]
    return res

def process_log(log):
    log = log.split()
    time = log[1].split(':')
    time += time[2].split('.')
    time = list(map(int, time[:2] + time[3:]))
    time = data_to_seconds(time)
    span = int(float(log[2][:-1]) * 1000)
    return (time, span)

def solution(lines):
    # 1. process data
    lines_cnt = len(lines)
    in_times = []
    out_times = []
    for log in lines:
        time, span = process_log(log)
        in_times.append(time - span + 1)
        out_times.append(time)
    in_times.sort()
    out_times.sort()

    # 2. initialize variables
    curr_time = in_times[0]
    curr_ans = 0
    s, e = 0, 0
    out_idx = 0
    while in_times[e] <= curr_time + 999:
        e += 1
        curr_ans += 1
        if e == lines_cnt:
            break
    e -= 1
    max_ans = curr_ans

    # 3. find answer
    while s < lines_cnt - 1 and e < lines_cnt - 1:
        # 시작점이 구간 밖으로 나가는 게 더 빠르면
        if in_times[s+1] - curr_time < in_times[e+1] - (curr_time + 999):
            s += 1
            curr_time = in_times[s]
        # 시작점이 구간 안으로 들어오는 게 더 빠르면
        else:
            e += 1
            curr_time = in_times[e] - 999
            curr_ans += 1
            # 그 과정에서 아예 나가는 게 하나 이상 발생하면 개수 세어 차감
            while True:
                if out_times[out_idx] >= curr_time:
                    break
                out_idx += 1
                if out_idx >= lines_cnt:
                    break
                curr_ans -= 1
        # 갱신
        if max_ans < curr_ans:
            max_ans = curr_ans
            
    return max_ans