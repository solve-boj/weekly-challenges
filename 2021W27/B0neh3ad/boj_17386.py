def cross(x1, y1, x2, y2):
    return x1*y2 - x2*y1


def between_points(p_lst):
    std = [p_lst[1][0] - p_lst[0][0], p_lst[1][1] - p_lst[0][1]]
    result = 1
    for x, y in p_lst[2:]:
        result *= cross(std[0], x - p_lst[0][0], std[1], y - p_lst[0][1])
    return 1 if result < 0 else 0
    

p = []
for i in range(2):
    a, b, c, d = map(int, input().split())
    p.append([a, b])
    p.append([c, d])

result = 1
result *= between_points(p)
result *= between_points(p[2:] + p[:2])

print(result)
