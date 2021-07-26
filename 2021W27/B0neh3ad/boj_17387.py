def cross(x1, y1, x2, y2):
    return x1*y2 - x2*y1


def include_point(p1, p2, q):
    return (q[0] - p1[0]) * (q[0] - p2[0]) <= 0 and (q[1] - p1[1]) * (q[1] - p2[1]) <= 0


def check_relative_position(p_lst):
    '''
    선분을 연장한 직선 위에 점이 있는 경우: 점이 선분 위에 있다면 2, 아니면 0
    그렇지 않은 경우: 외적이 -이면 1, +이면 0
    '''
    result1 = cross(p_lst[1][0] - p_lst[0][0], p_lst[2][0] - p_lst[0][0], p_lst[1][1] - p_lst[0][1], p_lst[2][1] - p_lst[0][1])
    result2 = cross(p_lst[1][0] - p_lst[0][0], p_lst[3][0] - p_lst[0][0], p_lst[1][1] - p_lst[0][1], p_lst[3][1] - p_lst[0][1])
    if (result1 == 0 and include_point(p_lst[0], p_lst[1], p_lst[2])) or (result2 == 0 and include_point(p_lst[0], p_lst[1], p_lst[3])):
        return 2

    return 1 if (result1 * result2 < 0) else 0
    
p = []
for i in range(2):
    a, b, c, d = map(int, input().split())
    p.append([a, b])
    p.append([c, d])

result = 0
result += check_relative_position(p)
result += check_relative_position(p[2:] + p[:2])

print(int(result >= 2))