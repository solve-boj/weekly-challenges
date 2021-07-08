def cross(x1, y1, x2, y2):
    return x1*y2 - x2*y1


def include_point(p1, p2, q):
    '''
    한 직선 위 세 점 p1, p2, q에 대하여 선분 p1p2가 q를 포함하는지 여부를 return
    '''
    return (q[0] - p1[0]) * (q[0] - p2[0]) <= 0 and (q[1] - p1[1]) * (q[1] - p2[1]) <= 0


def check_relative_position(std_line, cmp_line):
    '''
    std_line을 기준으로 했을 때, cmp_line과의 교점이 "존재할 수 있는" 조건인지 여부를 return
    '''
    result = 1
    for x, y in cmp_line:
        result *= cross(std_line[1][0] - std_line[0][0], x - std_line[0][0], std_line[1][1] - std_line[0][1], y - std_line[0][1])
        if result == 0:
            if include_point(std_line[0], std_line[1], [x, y]):
                return 2
            else:
                break

    return 1 if result < 0 else 0

t = int(input())

for _ in range(t):
    temp = list(map(int, input().split()))
    line = [temp[0:2], temp[2:4]]
    square = [temp[4:6], temp[6:8]]

    # 선분의 두 점이 직사각형 내에 있는 경우

    result = 0
    result += check_relative_position(p[:2], p[2:])
    result += check_relative_position(p[2:], p[:2])

    print(int(result >= 2))
